#include <iostream>
#include <string>

// LSP - Liskov Subtitution Principle
// SuperClass worked similar as SubClass in code that call them

//
//  BaseHuman
//
class BaseHuman{
public:
    friend std::ostream& operator<< (std::ostream& out, const BaseHuman& base_human);
    
    BaseHuman(){}
    virtual ~BaseHuman(){}

    virtual void go(){
        std::cout << "<---->" << std::endl;
        std::cout << "Called BaseHuman method go!" << std::endl;
    }
};

std::ostream& operator<< (std::ostream& out, const BaseHuman& base_human){
    out << "BaseHuman";

    return out;
}

//
//  Human
//
class Human: public BaseHuman{
public:
    friend std::ostream& operator<< (std::ostream& out, const Human& human);

    explicit Human(std::string inName, int inAge, float inWeight):
        m_name(inName), m_age(inAge), m_weight(inWeight)
    {}

    void go(){
        //BaseHuman::go();
        std::cout << "<---->" << std::endl;
        std::cout << "Called Human method go!" << std::endl;
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
    out << static_cast<BaseHuman>(human) << std::endl
        << "Human: " 
        << human.m_name << " | "
        << human.m_age << " | "
        << human.m_weight;

    return out;
}

void call_testing_by_ref(BaseHuman& h);
void call_testing_by_ptr(BaseHuman* h);


int main(){
    BaseHuman base_human;
    std::cout << base_human << std::endl;
    //base_human.go();

    Human human("Lev Grodzitskiy", 32, 111.3);
    std::cout << human << std::endl;
    //human.go();

    call_testing_by_ref(base_human);
    call_testing_by_ref(human);

    call_testing_by_ptr(&base_human);
    call_testing_by_ptr(&human);

    std::cout << "Done!" << std::endl;    
    return 0;
}


void call_testing_by_ref(BaseHuman& h){
    h.go();
}

void call_testing_by_ptr(BaseHuman* h){
    h->go();
}
