#include<iostream>
using namespace std;
class B;

class A{
    private:
        int a = 110;
    friend B;
};
class B{
    public:
        A m;
        void fun(){
            cout<<m.a;
        }
};

int main()
{
    B hi;
    hi.fun();
    return 0;
}