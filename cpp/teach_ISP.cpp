#include <iostream>
#include <string>

// Interface Segregation Principle - ISP
// It's better to have several small interfaces than big one

/*
--> Interfaces
*/

//
//  Interface of Document
//
class IDocument{
public:
    virtual ~IDocument(){}

    virtual std::string getPath() const = 0;

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void save() = 0;
};

//
//  Interface of Scanner
//
class IScanner{
public:
    virtual ~IScanner(){}

    virtual void scan_document(IDocument& doc) = 0;
    virtual void scan_image(const std::string& path) = 0;
};

//
//  Interface of Printer
//
class IPrinter{
public:
    virtual ~IPrinter(){}

    virtual void print_document(IDocument& doc) = 0;
    virtual void print_image(const std::string& path) = 0;
};


/*
--> Realisations
*/

//
//  Regular Document realisation
//
class RegularDocument: public IDocument{
public:
    explicit RegularDocument(std::string path):
        m_path(path)
    {}

    std::string getPath() const{
        return m_path;
    }    

    void open(){
        std::cout << m_path << " opened!" << std::endl;
    }

    void close(){
        std::cout << m_path << " closed!" << std::endl;
    }
    
    void save(){
        std::cout << m_path << " saved!" << std::endl; 
    }

private:
    std::string m_path;
};

//
//  Goverment Document Realisation
//
class GovernmentDocument: public IDocument{
public:
    explicit GovernmentDocument(std::string path):
        m_path(path)
    {}

    std::string getPath() const{
        return m_path;
    }

    void open(){
        std::cout << "Government " << m_path << " opened!" << std::endl;
    }

    void close(){
        std::cout << "Government " << m_path << " closed!" << std::endl;
    }

    void save(){
        std::cout << "Government " << m_path << " saved!" << std::endl;
    }

private:
    std::string m_path;
};


//
//  Regular Scanner realisation
//
class RegularScanner: public IScanner{
public:
    explicit RegularScanner(int devID):
        m_devID(devID)
    {}

    void scan_document(IDocument& doc){
        std::cout << "Document " << doc.getPath() << " scanned on " << m_devID << std::endl;
    }

    void scan_image(const std::string& path){
        std::cout << "Image " << path << " scanned on " << m_devID << std::endl;
    }

private:
    int m_devID;
};

//
//  Regular Printer realisation 
//
class RegularPrinter: public IPrinter{
public:
    explicit RegularPrinter(int devID):
        m_devID(devID)
    {}

    void print_document(IDocument& doc){
        std::cout << "Document " << doc.getPath() << " printed on " << m_devID << std::endl;
    }    

    void print_image(const std::string& path){
        std::cout << "Document " << path << " printed on " << m_devID << std::endl;
    }

private:
    int m_devID;
};


//
//  MFP realisation
//
class MFP: public IScanner, IPrinter{
public:
    explicit MFP(int devID):
        m_devID(devID)
    {}

    void scan_document(IDocument& doc){
        std::cout << "Document " << doc.getPath() << " scanned on " << m_devID << std::endl;
    }

    void scan_image(const std::string& path){
        std::cout << "Image " << path << " scanned on " << m_devID << std::endl;
    }

    void print_document(IDocument& doc){
        std::cout << "Document " << doc.getPath() << " printed on " << m_devID << std::endl;
    }

    void print_image(const std::string& path){
        std::cout << "Image " << path << " printed on " << m_devID << std::endl;
    }

private:
    int m_devID;
};

int main(){
    RegularDocument reg_doc("1.docx");
    reg_doc.open();
    reg_doc.save();
    reg_doc.close();

    GovernmentDocument gov_doc("1.govx");
    gov_doc.open();
    gov_doc.save();
    gov_doc.close();

    RegularScanner reg_scanner(10011);
    reg_scanner.scan_document(reg_doc);
    reg_scanner.scan_document(gov_doc);

    RegularPrinter reg_printer(10012);
    reg_printer.print_document(reg_doc);
    reg_printer.print_document(gov_doc);

    MFP mfp(10010);
    mfp.scan_document(reg_doc);
    mfp.print_document(reg_doc);
    mfp.scan_document(gov_doc);
    mfp.print_document(gov_doc);

    std::cout << "Done!" << std::endl;

    return 0;
}
