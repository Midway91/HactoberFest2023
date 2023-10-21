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
    rectangle(){
        length = 0;
        breadth = 0;
    }
    rectangle(int l , int b){
        setLength(l);
        setBreadth(b);
    }
    rectangle(rectangle (&rect)){
        length = rect.length;
        breadth = rect.breadth;
    }

};
int main()
{
    rectangle r;
    rectangle r();
    rectangle r(10 , 5);
    rectangle r2(r);

    return 0;
}