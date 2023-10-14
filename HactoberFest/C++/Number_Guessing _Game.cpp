#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main(){
    system("cls");
    cout<<"==========||  NUMBER GUESSING GAME  ||=========="<<endl<<endl;
    bool wnt_play;
    int a;
    cout<<"Want to play Number Guessing game with me?"<<endl;
    cout<<"1. Yes"<<endl<<"2. No"<<endl;
    cin>>a;
    if(a==1){
        wnt_play=1;
    }
    else{
        wnt_play=0;
    }
    while(wnt_play){
        system("cls");
        cout<<"Ok! Let me think a number..."<<endl;
        srand((unsigned) time(NULL));
        int original_num = 1 + (rand() % 100);
        int guessed_num=-1, attempts = 0;
        sleep(3);
        cout<<"Done...Now it's your turn. Read my mind which number i had guessed just now :)"<<endl;
        cout<<"(Hint: My number lies between 1 & 100)"<<endl;
        while(guessed_num!=original_num){
            attempts++;
            cin>>guessed_num;
            sleep(1);
            if(guessed_num>original_num){
                cout<<"Wrong! You guessed a high number..."<<endl;
                cout<<"My number is below "<<guessed_num<<endl;
                cout<<"Try again!!"<<endl;
            }
            else if(guessed_num<original_num){
                cout<<"Wrong! You guessed a low number..."<<endl;
                cout<<"My number is above "<<guessed_num<<endl;
                cout<<"Try again!!"<<endl;
            }
            else{
                cout<<"cool champ! you guessed correct number in "<<attempts<<" attempts."<<endl;
                break;
            }
        }
        cout<<"Do you want to play another game?"<<endl;
        cout<<"1. Yes"<<endl<<"2. No"<<endl;
        cin>>a;
        if(a==1){
            wnt_play=1;
        }
        else{
            wnt_play=0;
        }
    }
    system("cls");
    sleep(1);
    cout<<"I think you are out of time."<<endl;
    sleep(1);
    cout<<"See you later...Have a nice day :)"<<endl;
    return 0;
}