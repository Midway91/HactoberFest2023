#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class Items{
    private:
        string name;
        int price;
        int quantity;
    
    public:
        friend ofstream & operator<<(ofstream &ofc , Items &it);
        friend ifstream & operator>>(ifstream &ifi , Items &it);
        friend ostream & operator<<(ostream &os , Items &it);
        Items(){};
        Items(string name , int price , int quantity){
            this->name = name;
            this->price = price;
            this->quantity = quantity;
        }
};

ofstream & operator<<(ofstream &ofc , Items &it){
    ofc<<it.name<<endl;
    ofc<<it.price<<endl;
    ofc<<it.quantity<<endl;
    return ofc;
}

ifstream & operator>>(ifstream &ifi , Items &it){
    ifi>>it.name;
    ifi>>it.price;
    ifi>>it.quantity;
}

ostream & operator<<(ostream &os , Items &it){
    os<<it.name<<endl;
    os<<it.price<<endl;
    os<<it.quantity<<endl;
}

int main()
{
    string nam;
    int pri;
    int qt;
    int n;
    
    cout<<"Enter Number Of Items You Want To Save"<<endl;
    cin>>n;
    vector<Items *> list;

    cout<<"****Enter Items From Here****"<<endl;
    
    for(int i = 0 ; i < n ; i++){
        cout<<"Enter Information About "<<i+1<<" item"<<endl;
        cin>>nam;
        cin>>pri;
        cin>>qt;
        list.push_back( new Items(nam , pri , qt));

    }
     
    ofstream inpufil("Items.txt" , ios::trunc);
   vector<Items *>::iterator itr;
   for(itr = list.begin() ; itr!= list.end() ; itr++){
    inpufil<<**itr;
   }
    inpufil.close();

    Items item;
    ifstream redfil("Items.txt");
    for(int i = 0 ; i < n ; i++){
        redfil>>item;
        cout<<"Item Number "<<i+1<<" Is"<<endl;
        cout<<item;
    }
    redfil.close();

    

    return 0;
}