#include<iostream>
using namespace std;
class ratNo{
    private:
        int nume;
        int deno;
    public:
        ratNo(int nume = 0 , int deno = 0){
            this-> nume = nume;
            this-> deno = deno;

        }
        friend ratNo operator+(ratNo r1 , ratNo r2);
        friend ostream& operator<<(ostream &dede , ratNo r);
};
ostream& operator<<(ostream &dede , ratNo r){
    dede<<r.nume<<"/"<<r.deno<<endl;
    return dede;
}
ratNo operator+(ratNo r1 , ratNo r2){
    ratNo temp;
    temp.nume = r1.nume + r2.nume;
    temp.deno = r1.deno + r2.deno;
    return temp;
}
int main()
{
    ratNo n1(2,3);   
    ratNo n2(4,5);
    cout<<n1<<endl;
    cout<<n2<<endl;
    ratNo sum = n1 + n2;
    cout<<sum<<endl;
    return 0;
}