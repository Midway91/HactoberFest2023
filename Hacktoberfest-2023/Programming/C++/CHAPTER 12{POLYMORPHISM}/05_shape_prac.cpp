#include<iostream>
using namespace std;
class shape{
    public:
        virtual float area() = 0;
        virtual float perimeter() = 0;
};
class rectangle : public shape{
    private:
        int length;
        int width;
    public:
        rectangle(int length , int width){
            this ->length = length;
            this ->width = width;
        }
        float perimeter(){
            return 2*(length + width);
        }
        float area(){
            return length*width;
        }
};
int main()
{
    shape *ptr = new rectangle(22 , 33);
    cout<<ptr ->area()<<endl;
    

    return 0;
}