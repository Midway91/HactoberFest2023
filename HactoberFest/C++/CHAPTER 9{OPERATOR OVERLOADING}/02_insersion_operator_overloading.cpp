#include<iostream>
using namespace std;
class complex{
    private:
    int real;
    int img;
    public:
    complex(int r = 0 , int i = 0){
        real = r;
        img = i;
    }
    friend ostream& operator<<(ostream &o,complex &c1);
};
ostream& operator<<(ostream &o, complex &c1){
    o<<c1.real<<"+ i"<<c1.img;
    return o;
}
int main(){
    complex c1(10 , 4);
    cout<<c1;
    return 0;
}
