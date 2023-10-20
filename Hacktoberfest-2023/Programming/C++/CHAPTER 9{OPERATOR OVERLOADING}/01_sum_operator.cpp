#include<iostream>
using namespace std;
class complex{
    public:
        int real;
        int img;
    
        complex(int r = 0, int i = 0){
            real = r;
            img = i;
        }
        // complex add(complex x){}
        complex operator+(complex x){
            complex temp;
            temp.real = real + x.real;
            temp.img = img + x.img;
            return temp;
        }
};
int main(){
    complex c1(4,5);
    complex c2(6,7);
    // complex c3 = c1.add(c2);
    complex c3 = c1 + c2;
    cout<<c3.real<<"+ i"<<c3.img<<endl;
    
    return 0;
}