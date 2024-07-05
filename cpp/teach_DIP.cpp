#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>

using namespace std::chrono;

// Dependency Inversion Principle - DIP
// SuperModules and SubModule depend on interfaces, but not between themselves

//
//  Logger Interface
//
class ILogger{
public:
    virtual ~ILogger(){}

    virtual void log(const std::string& message) = 0;
};

//
//  Proto of Separated Logger Module
//
class Logger: public ILogger{
public:
    explicit Logger(){}

    void log(const std::string& message){
        std::cout << "Just logging " << message << " ..." << std::endl;
    }
};

//
// Proto of DataBase Module
//
class DataBase: public ILogger{
public:
    explicit DataBase(std::string name):
        m_name(name), m_isReady(false)
    {}

    std::string getName() const{
        return m_name;
    }

    void log(const std::string& message){
        std::cout << "<DB> Logging " << message << " ..." << std::endl;
    } 

    void open(){
        m_isReady = true;
        log("<DB> " + m_name + " opened for transactions!");
    }

    void close(){
        m_isReady = false;
        log("<DB> " + m_name + " closed for transactions!");
    }

    void do_request(std::string request){
        if (!m_isReady){
            log("<DB> " + m_name + " is not ready for transactions!");
            return;
        }

        std::this_thread::sleep_for(300ms);
        log("<DB> " + m_name + " query '" + request + "' completed!");
    }

private:
    std::string m_name;
    bool        m_isReady;
};


//
//  Proto of File Module
//
class File: public ILogger{
public:
    explicit File(std::string path):
        m_path(path),
        m_isReady(false)
    {}

    std::string getPath() const{
        return m_path;
    }

    void log(const std::string& message){
        std::cout << "<FILE> Logging " << message << " ..." << std::endl;
    }

    void open(){
        m_isReady = true;
        log("<FILE> " + m_path + " opened for operatoins!");
    }

    void close(){
        m_isReady = false;
        log("<FILE> " + m_path + " closed for operations!");
    }

    std::string read(){
        if (!m_isReady){
            log("<FILE> " + m_path + " is not ready for operations!");
            return std::string();
        }

        std::this_thread::sleep_for(10ms);
        log("<FILE> " + m_path + " has been read!");
        return "string";
    }

    void write(std::string s){
        if(!m_isReady){
            log("<FILE> " + m_path + " is not ready for operations!");
            return;
        }

        std::this_thread::sleep_for(10ms);
        log("<FILE> " + m_path + " wrote string " + s + "!");
    }

    void clear(){
        if(!m_isReady){
            log("<FILE> " + m_path + " is not ready for operations!");
            return;
        }
        
        std::mt19937 mt{std::random_device{}()};
        std::uniform_real_distribution<> rand_range{0.01, 2.5};
        double rand_val = rand_range(mt);
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(rand_val * 1000)));

        log("<FILE> " + m_path + " was cleared!");
    }

private:
    std::string m_path;
    bool        m_isReady;
};


int main(){
    Logger logger;
    logger.log("bumbaracha!");

    DataBase db("Sample");
    db.open();
    db.do_request("create table init");
    db.close();

    File f("1.docx");
    f.open();
    std::string stroke = f.read();
    std::cout << stroke << std::endl;
    f.clear();
    f.write(stroke);
    f.close();

    std::cout << "Done!" << std::endl;
    
    return 0;
}
