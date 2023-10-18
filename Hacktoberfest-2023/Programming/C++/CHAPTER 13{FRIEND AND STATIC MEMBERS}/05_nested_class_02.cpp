#include<iostream>
using namespace std;
class Outer{
   
    private:
        int a = 10;
    public:
        int b = 11;
        static int d ;
        void display(){
            
            cout<<i.l<<endl;
            // cout<<i.m<<endl; not ok
            // cout<<i.n<<endl; not ok

        }
    class Inner{
        public:
            int l = 966;
        
        protected:
            int n = 333;
            
        private:
            int m = 990;

                
                
                
            
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

