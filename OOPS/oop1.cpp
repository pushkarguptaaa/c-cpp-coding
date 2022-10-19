#include <iostream>
using std::string;

class AbstractEmployee{
    virtual void AskForPromotion()= 0;
};

class Employee:AbstractEmployee{
    private:
    string Company;
    int Age;

    protected:
    string Name;

    public:
    void setName(string name){ //setter
        Name = name;
    }
    string getName(){ //getter
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if(age>=18)
        Age = age;
    }
    int getAge(){
        return Age;
    }

    void IntroduceYourself(){
        std::cout<<"Name - " << Name << std::endl;
        std::cout<<"Company - " << Company << std::endl;
        std::cout<<"Age - " << Age << std::endl;
    }

    Employee(string name, string company, int age){
        Name = name;
        Company= company;
        Age=age;

    }
    
    void AskForPromotion(){
        if(Age>30)
        std::cout<<Name<< " got promoted"<<std::endl;
        else       
        std::cout<<Name<< " , sorry NO promotion for you!"<<std::endl;
    }

    void Work(){
        std::cout<<Name<< " is checking email, task backlog, performing tasks..."<<std::endl;
    }
};

class Developer: public Employee{
    public:
    string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favProgrammingLanguage)
    :Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void FixBug(){
        std::cout<<Name<< " fixed bug using "<<FavProgrammingLanguage<<std::endl;
    }

    void Work(){
        std::cout<< Name<< " is writing "<< FavProgrammingLanguage<< " code"<<std::endl;
    }
};

class Teacher: public Employee{
    public:
    string Subject;
    void PrepareLesson(){
        std::cout<<Name<< " is preparing "<<Subject<< " lesson"<<std::endl;
    }
   
    Teacher(string name, string company, int age, string subject)
    :Employee(name, company, age)
    {
        Subject = subject;
    }

    void Work(){
        std::cout<< Name<< " is teaching "<< Subject<<std::endl;
    }
};

int main(){
    // Employee employee1= Employee("Pushkar", "CU", 20);
    // employee1.IntroduceYourself();

    // Employee employee2= Employee("Anu", "Housewife", 42);
    // employee2.IntroduceYourself();

    // employee1.setAge(15);
    // std::cout<<employee1.getName()<<" is "<< employee1.getAge()<<" years old"<<std::endl;

    // employee1.AskForPromotion();
    // employee2.AskForPromotion();

    Developer d = Developer("Pushkar", "CU", 20, "C++");
    // d.FixBug();
    // d.AskForPromotion();
   
    Teacher t = Teacher("Nirmal", "CSH", 45, "Games");
    // t.PrepareLesson();
    // t.AskForPromotion();

    d.Work();
    t.Work();
}