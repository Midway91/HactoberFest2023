#include <iostream>

using namespace std;

 //Create classes Rectangle and RectangleArea
 
class Rectangle{
    public:
    int width;
    int height;
    void display(){
        cout<<width<<" "<<height<<"\n";

    }
};
class RectangleArea: public Rectangle{
    public:
    void read_input(){
        cin>>width>>height;
    }
    void display(){
        int rarea=width*height;
        cout<<rarea;
    }
    
};
// display() method has been overloaded in this program so as to find the area of the rectangle.
int main()
{
    
      //Declare a RectangleArea object
     
    RectangleArea r_area;
    
    
     //Read the width and height
     
    r_area.read_input();
    
    
     //Print the width and height
     
    r_area.Rectangle::display();
    
    
    
     //Print the area
     
    r_area.display();
    
    return 0;
}