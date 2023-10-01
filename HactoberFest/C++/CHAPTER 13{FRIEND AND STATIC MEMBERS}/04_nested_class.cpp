#include<iostream>
using namespace std;
class Outer{
   
    private:
        int a = 10;
    public:
        int b = 11;
        static int d ;
        void display(){
            i.pro();
            cout<<i.l<<endl;
        }
    class Inner{
        public:
            int l = 966;
            void pro(){
                Outer c;
                cout<<c.b<<endl;
                cout<<c.a<<endl;
                
                cout<<Outer::d<<endl;
            }
    };
    Inner i;
    
};
int Outer::d = 555;
int main()
{
    Outer obj;
    obj.display();
    return 0;
}

