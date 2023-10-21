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

    int perimeter();
    
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
int rectangle::perimeter(){
    return 2*(length + breadth);
}
int main()
{
    
    return 0;
}