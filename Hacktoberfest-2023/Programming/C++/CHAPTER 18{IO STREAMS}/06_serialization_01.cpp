#include<iostream>
#include<fstream>
using namespace std;
class Student
{
    public:
        string name;
        int roll;
        string branch;
        friend ifstream & operator>>(ifstream &ifs , Student &s);
};
ifstream & operator>>(ifstream &ifs , Student &s){
    ifs>>s.name>>s.roll>>s.branch;
    return ifs;

}
int main()
{
    Student s1;
    Student s2;
    ifstream infile("Student.txt");
    infile>>s1;
    infile>>s2;
    cout<<s1.name<<s1.roll<<s1.branch<<endl;
    cout<<s2.name<<s2.roll<<s2.branch<<endl;
    infile.close();
    return 0;
}