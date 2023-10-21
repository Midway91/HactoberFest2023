#include<iostream>
#include<memory>
using namespace std;
class Rectangle{
    private:
        int length;
        int breadth;
    public:
        Rectangle(int length , int breadth){
            this->length = length;
            this->breadth = breadth;
        }
        int area(){
            return length*breadth;
        }
};

int main()
{
    shared_ptr<Rectangle> ptr(new Rectangle(10,5));
    shared_ptr<Rectangle> ptr2;
    ptr2 = ptr;
    
    
    cout<<ptr->area();
    cout<<ptr2->area();
    cout<<ptr.use_count()<<endl;
    
    return 0;
}