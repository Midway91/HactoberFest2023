#include<iostream>
using namespace std;
class Test{
    private:
        int a;
    protected:
        int b;
    public:
        int c;
        friend void fun();
};
void fun(){
    Test t;
    t.a = 10;
    t.b = 11;
    t.c = 12;
}
int main()
{

    return 0;
}