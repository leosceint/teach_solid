#include <iostream>
#include <string>

// Open-Closed Principle - OCP
// Opened for extension. Closed for modification


//
//  Interface of Human
//
class InterfaceHuman{
public:
    friend std::ostream& operator<< (std::ostream& out, const InterfaceHuman& iHuman);
    
    virtual ~InterfaceHuman() {}
    
    virtual void go() = 0;  // {}   // pass statement from Python == empty block statement {} in C++
                                    // but that is not pure virtual
};

std::ostream& operator<< (std::ostream& out, const InterfaceHuman& iHuman){
    return out;
}

//
//  Human
//
class Human: public InterfaceHuman{
public:
    friend std::ostream& operator<< (std::ostream& out, const Human& human);
    
    explicit Human(std::string inName, int inAge, float inWeight):
        m_name(inName),
        m_age(inAge),
        m_weight(inWeight)
    {}

    void go(){
        //InterfaceHuman::go(); // Error while Interface method is pure virtual !!!
        std::cout << "Human " << m_name << " GO!" << std::endl;
    }

    std::string getName() const{
        return m_name;
    }

private:
    std::string m_name;
    int         m_age;
    float       m_weight;
};

std::ostream& operator<< (std::ostream& out, const Human& human){
    out << "Human: " 
    << human.m_name << " | "
    << human.m_age << " | "
    << human.m_weight;

    return out;
}


//
//  Employee
//
class Employee: public Human{
public:
    friend std::ostream& operator<< (std::ostream& out, const Employee& employee);

    explicit Employee(std::string inName, int inAge, float inWeight, int inIDcard):
        Human(inName, inAge, inWeight),
        m_IDcard(inIDcard)
    {}

    void go(){
        std::cout << "Employee " 
        << getName() << " | " 
        << getIDcard() << " GOO!!" << std::endl;
    }

    int getIDcard() const{
        return m_IDcard;
    }

private:
    int m_IDcard;
};

std::ostream& operator<< (std::ostream& out, const Employee& employee){
    out << static_cast<Human>(employee) << " | " << employee.m_IDcard;

    return out;
}


int main(){
    Human human("Lev Grodzitskiy", 32, 111.3);
    std::cout << human << std::endl;
    human.go();

    Employee employee("Lev Grodzitskiy", 32, 111.3, 45183);
    std::cout << employee << std::endl;
    employee.go();

    std::cout << "Done!" << std::endl;

    return 0;
}
