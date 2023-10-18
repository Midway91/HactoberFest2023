#include <iostream>
#include <cmath>
using namespace std;
/*Construct a Program in C++ to show the working of function overloading(compile 
time polymorphism) by using a function named calculate Area () to calculate area 
of square, rectangle and triangle using different signatures as required.*/
float Area(float side)
{
    return side*side;
}
float Area(float length,float width)
{
    return length*width;
}
float Area(float s1,float s2,float s3)
{
    float p=(s1+s2+s3)/2;
    float area=sqrt(p*(p-s1)*(p-s2)*(p-s3));
    return area;
}
int main()
{
    float side,length,breadth,a,b,c;
    cout<<"Input the length of side of square : "<<endl;
    cin>>side;
    cout<<"Input the length and breadth of the rectangle : "<<endl;
    cin>>length>>breadth;
    cout<<"Input the 3 sides of triangle : "<<endl;
    cin>>a>>b>>c;
    cout<<"Area of square : "<<Area(side)<<endl;
    cout<<"Area of the rectangle : "<<Area(length,breadth)<<endl;
    cout<<"Area of the triangle : "<<Area(a,b,c)<<endl;
    return 0;
}
