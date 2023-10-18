#include<iostream>
using namespace std;
class Test{
    private:
        int a;
    public:
        static int count;
        Test(){
            a = 10;
            count++;
        }
        static int getCount(){
            // a = 22; can't access non static members
            return count; //only access static members

        }

};
int Test::count = 0;

int main()
{
    Test t1;
    cout<<t1.count<<endl;
    cout<<t1.getCount()<<endl;
    cout<<Test::count<<endl;
    cout<<Test::getCount<<endl;
    Test t2;
    cout<<t2.count<<endl;
    
    return 0;
}