#include<iostream>
using namespace std;
class Car{
    public:
        virtual void start() = 0;
 
        virtual void stop() = 0;
};
class Benz :public Car{
    public:
        void start(){
            cout<<"Innova Started";
        }
        void stop(){
            cout<<"Innova Stopped";
        }
};
int main()
{
    Car *ptr = new Benz();
    ptr ->start();
    return 0;
}