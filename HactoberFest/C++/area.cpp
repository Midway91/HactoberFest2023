#include<iostream>
using namespace std;
class area{
    public:
        int area;
        int l;
        int b;
       

        int areaofrect(int len, int bread){
            cout<<"Enter the len  "<<endl;
            cin>>l;
            cout<<"Enter the breadth  "<<endl;
            cin>>b;
            area=l*b;
            cout<<area<<endl;
            return 0;
        }
        int peri(int l, int b);
};

int area::peri(int a,int c){
    int peri;
            cout<<"Enter the len  "<<endl;
            cin>>l;
            cout<<"Enter the breadth  "<<endl;
            cin>>b;
    peri=2*(l+b);

    cout<<peri<<endl;
    }

int main(){
    area rect1,sqr2;
    
    rect1.areaofrect(2,3);
    rect1.peri(2,3);
    

}