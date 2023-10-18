#include<iostream>
using namespace std;
class rectangle

{

private:
    int length;

    int breadth;
public:
    void setLength(int l){
        if(l>0){
            length = l;
        }
        else{
            length = 0;
        }
    }
    void setBreadth(int b){
        if(b>0){
            breadth = b;
        }
        else{
            breadth = 0;
        }
    }
    int showLength(){
        return length;
    }
    int showBreadth(){
        return breadth;
    }
    int area()
    {

        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }

};
int main()
{
    rectangle r;
    r.setLength(15);
    r.setBreadth(10);
    cout<<"length is "<<r.showLength()<<endl;
    cout<<"breadth is "<<r.showBreadth()<<endl;
    cout<<"area is "<<r.area()<<endl;
    cout<<"perimeter is "<<r.perimeter()<<endl;
    return 0;
}