#include<iostream>
using namespace std;
class Rectangle{
    private:
        int length = length;
        int breadth = breadth;
    public:
        void setLength(int l){
            if(l > 0){
                length = l;
            }
            else{
                length = 0;
            }
        }
        void setBreadth(int b){
            if(b > 0){
                breadth= b;
            }
            else{
                breadth = 0;
            }
        }
        protected:
            int getLength(){
                return length;
            }
            int getBreadth(){
                return breadth;
            }
};
class Cuboid:Rectangle{
    public:
        void funDerived(){
            setLength(20);
            setBreadth(30);
            cout<<getBreadth()<<endl;
            cout<<getLength()<<endl;

        }

};
int main()
{
    Cuboid c1;
    c1.funDerived();
    // c1.getLength();
    Rectangle r1;
    // r1.length = 10;
    // r1.breadth = 15;
    r1.setLength(10);
    r1.setBreadth(15);
    // cout<<(r1.getLength())<<endl;
    // cout<<(r1.getBreadth())<<endl;
    return 0;
}