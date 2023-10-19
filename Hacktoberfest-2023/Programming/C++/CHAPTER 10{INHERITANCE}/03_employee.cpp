#include<iostream>
using namespace std;
class Employee{
    private:
        string name;
        int id;
    public:
        Employee(string name, int id){
            this->name = name;
            this->id = id;
        }
        int getId(){
            return id;
        }
        string getName(){
            return name;
        }
};

class FullTimeEmployee:public Employee{
    private:
        int salary;
    public:
        FullTimeEmployee(string name , int id , int salary):Employee(name , id){
            this->salary = salary;
        }
        int getSalary(){
            return salary;
        }
};

class PartTimeEmployee:public Employee{
    private:
        int wage;
    public:
        PartTimeEmployee(string name , int id , int wage):Employee(name , id){
            this->wage = wage;
        }
        int getWage(){
            return wage;
        }
};

int main()
{
    FullTimeEmployee p1("Anushk" , 19 , 3000000);
    PartTimeEmployee p2("Aryan" , 21 , 4000);

    cout<<"Salary Of "<<p1.getName()<<" is "<<p1.getSalary()<<endl;

    cout<<"Daily Wage Of "<<p2.getName()<<" is "<<p2.getWage()<<endl;

    cout<<"ID Of Fulltime Employee is "<<p1.getId()<<endl;

    cout<<"ID Of Parttime Employee is "<<p2.getId()<<endl;

    return 0;
}