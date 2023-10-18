#include<iostream>
using namespace std;
class rectangle{
    private:
    int length;
    int breadth;
    public:
    rectangle(int l = 0 , int b = 0){
        length = l;
        breadth = b;
    }
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
    int perimeter(){
        return 2*(length + breadth);
    }
};
class cuboid:public rectangle{
    private:
    int height;
    public:
    cuboid(int l = 0 , int b = 0 , int h = 0){
        setHeight(h);
        setLength(l);
        setBreadth(b);
    }
    int setHeight(int h){
        if(h > 0){
            height = h;
        }
        else{
            height = 0;
        }
    }
    int showHeight(){
        return height;
    }
    int volume(){
        return showLength()*showBreadth()*height;
    }

};
int main()
{
    cuboid c1(10 , 5 , 3);   
    cout<<c1.volume();
    return 0;
}