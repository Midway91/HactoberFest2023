#include<iostream>
using namespace std;
class complex{
    private:
        int real;
        int img;
    public:
        complex(int r = 0, int i = 0){
            real = r;
            img = i;
        }
        void display(){
            cout<<real<<"+ i"<<img;
        }
        friend complex operator+(complex c1 , complex c2);
};
complex operator+(complex c1,complex c2){
    complex t;
    t.real = c1.real + c2.real;
    t.img = c1.img + c2.img;
    return t;

}
int main()
{   
    complex a1(10 , 9);
    complex a2(8,7);
    complex sum = a1 + a2;
   sum.display();
    return 0;
}