#include<iostream>
#include<string.h>
using namespace std;
class student{
    private:
    int roll , marks1 , marks2 , marks3 , totalMarks; 
    string name[30];
    public:
    void setRoll(int r){
        if(r>0){
            roll = r;
        }
        else{
            cout<<"Enter Correct Roll"<<endl;
            roll = 0;
        }
    }
    // void setName(string nam[30]){
    //     name[30] = nam[30];
    // }
    void setMarks(int m1 , int m2 , int m3){
        if(m1>0 && m2>0 && m3>0){
            marks1 = m1;
            marks2 = m2;
            marks3 = m3;
        }
        else{
            cout<<"Enter Correct Marks"<<endl;
            marks1 = 0;
            marks2 = 0;
            marks3 = 0;
        }
    }
    int displayRoll(){
        return roll;
    }
    // string displayName(){
    //     return name[30];
    // }
    int displayMarks(){
        return marks1 , marks2 , marks3;
    }
    int displayTotal(){
        totalMarks = marks1 + marks2 + marks3;
        return totalMarks;
    }
    char displayGrade(){
        if(totalMarks/3 > 10){
            return 'A';
        }
        else{
            return 'B';
        }
    }

};
int main()
{
    student loo;
    loo.setRoll(2);
    // loo.setName("ShyamPatel");
    loo.setMarks(22 , 32 , 42);
    cout<<"Roll No Is "<<loo.displayRoll()<<endl;
    // cout<<"Name Is "<<loo.displayName()<<endl;
    cout<<"Total Marks Is "<<loo.displayTotal()<<endl;
    cout<<"Grade Is "<<loo.displayGrade()<<endl;
    
    return 0;
}