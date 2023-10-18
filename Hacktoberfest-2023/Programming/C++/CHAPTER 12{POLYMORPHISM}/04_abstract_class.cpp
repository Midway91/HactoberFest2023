#include<iostream>
using namespace std;
// here the class car is is abstract class
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