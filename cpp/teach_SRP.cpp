#include <iostream>
#include <string>

// Single Responsibility Principle - SRP
// I do what I am responsible for

//
//  Human
//
class Human{
public:
    friend std::ostream& operator<< (std::ostream& out, const Human& h);

    explicit Human(std::string inName, int inAge, float inWeight):
        m_name(inName),
        m_age(inAge),
        m_weight(inWeight)
    {}

    void go(){
        std::cout << m_name << " GO!" << std::endl;
    }

    std::string getName() const{
        return m_name;
    }

    int getAge() const{
        return m_age;
    }

    float getWieght() const{
        return m_weight;
    }

private:
    std::string m_name;
    int         m_age;
    float       m_weight;

};

std::ostream& operator<< (std::ostream& out, const Human& h){
    out << "Human: " 
    << h.m_name << " | "
    << h.m_age << " | "
    << h.m_weight;

    return out;
}


int main(){
    Human human("Lev Grodzitskiy", 32, 111.3);
    std::cout << human << std::endl;

    std::cout << "Done!" << std::endl;
    return 0;
}
