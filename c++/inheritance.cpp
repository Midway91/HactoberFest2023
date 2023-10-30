// Understanding inheritance of class

#include<iostream>
using namespace std;

class Rectangle
{
    int len;
    int bre;

    public:
        Rectangle(int l=0, int b=0);

        int getLength(){ return len; }  // Accessors
        int getBreadth(){ return bre; }

        void setLength(int l);          // Mutators
        void setBreadth(int b);

        int area();
};

Rectangle :: Rectangle(int l, int b)        // Parameterized
{
    len = l;
    bre = b;
}

void Rectangle :: setLength(int l)          // Mutator
{
    if(l >= 0)
        len = l;
    else
        len = 0;
}

void Rectangle :: setBreadth(int b)
{
    if(b >= 0)
        bre = b;
    else
        bre = 0;
}

int Rectangle :: area()                     // Facilitator
{
    return len*bre;
}

// --------------------------------- Inherited Class --------------------------------
class Cuboid : public Rectangle
{
    int hei;

    public:
        Cuboid (int h = 0);

        int getHeight(){ return hei; }
        void setHeight(int h);
        
        int volume();
};

Cuboid :: Cuboid(int h)
{
    hei = h;
}

void Cuboid :: setHeight(int h)
{
    if(h >= 0)
        hei = h;
    else
        hei = 0;
}

int Cuboid :: volume()
{
    return getLength()*getBreadth()*hei;    // Need to use the funcs since len and bre are the private members of Rect
    // return area()*hei;                   // Alternate method
}

// ---------------------------- Main body ------------------------------
int main()
{
    int l,b,h;

    cout<<"Enter length: ";
    cin>>l;
    cout<<"Enter breadth: ";
    cin>>b;
    cout<<"Enter height: ";
    cin>>h;

    Cuboid c(h);
    c.setLength(l);
    c.setBreadth(b);

    cout<<"Volume is "<<c.volume()<<endl;

    return 0;
}