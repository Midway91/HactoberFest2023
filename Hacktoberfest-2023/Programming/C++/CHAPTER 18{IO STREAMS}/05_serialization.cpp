#include<iostream>
#include<fstream>
using namespace std;
class Student
{
    public:
        string name;
        int roll;
        string branch;
        friend ofstream & operator<<(ofstream &ofs , Student &s);
};
ofstream & operator<<(ofstream &ofs , Student &s){
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;
    return ofs;

}
int main()
{
    Student s1;
    s1.name = "arjun";
    s1.roll = 21;
    s1.branch = "IT";
    Student s2;
    s2.name = "aryan";
    s2.roll = 69;
    s2.branch = "Ip";
    ofstream outfile("Student.txt" , ios::trunc);
    outfile<<s1;
    outfile<<s2;
    outfile.close();
    return 0;
}