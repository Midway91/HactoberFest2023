#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>

using namespace std;

		string username = "";
		string password = "";
		char words;
class registration{
	
		public:
		
				void menu(){
		
		registration r2;
	char choice; // using char bcuz user can mistakenly enter alphabets/chars
	cout<<"\n\n\t\t\t\t\t_______________________________________";
	cout<<"\n\n\t\t\t\t\t\tWELCOME TO THE LOGIN PAGE";
	cout<<"\n\n\t\t\t\t\t_______________________________________";
	cout<<"\n\n\n\t\t\tPress 1 to login:";
	cout<<"\n\n\n\t\t\tPress 2 to register:";
	cout<<"\n\n\n\t\t\tPress 3 if you forgot your password:";
	cout<<"\n\n\n\t\t\tPress 4 to exit:";
	cout<<"\n\t\t\t\t\t\t\t\tPlease enter your choice: ";
	cin>>choice;
	system("cls");
	switch(choice){
		case '1':
			if(username.empty() && password.empty()) {
				cout << "You havent even registered yet! Pls register first.";
				menu();
			} else {
			r2.login();
			}
			break;
		case '2':
			r2.regis();
			break;
		case '3':
			if(username.empty() && password.empty()) {
				cout << "You havent even registered yet! Pls register first.";
				menu();
			} else {
			r2.forgot();
			}
			break;
		case '4':
			cout<<"\n\n\t\tThank You!";
			break;
				default:
					cout<<"\n\n\t\tPlease select the valid keys.";
					menu();
	}
	
}
		void forgot(){
				int choice;
				string name;
				cout<<"\n\n\t\tHave forgotten your password? We gotcha! \n";
				cout<<"Enter a choice: \n";
				cout<<"Press 1 to enter the last username: \n";
				cout<<"Press 2 to go back to main menu: \n";
				cin>>choice;
				system("cls");
				
				switch(choice){
					case 1:{
						cin.ignore();
						cout<<"Enter the last username you entered: \n";
						getline(cin,name);
						
						string temp = "\n\n\t\t\t_____SEARCHING_____\n";
						for(int i = 0; i < temp.length(); i++) {
						cout<<temp[i];
						Sleep(100);
						}
						if(name.compare(username)==0){
							cout<<"Your ID is found! \n";
							cout<<"Your password: "<<password;
							menu();
						}
						else{
							cout<<"Incorrect username! ID cannot be found.";
							menu();
						
						}
						break;
					}
					case 2:
						menu();
						break;
				}
				
			}
			void login(){
				string userID;
				string pw;
		
				cin.ignore();
				cout<<"Enter username: ";
				getline(cin,userID);
				cout<<"Enter password: \n";
				cout<<"(Your password is upto 9 characters only)";
					for(int i=1; i<=9; i++)
				{
					words=getch();	
					cout<<"*";
					pw+=words;
				}
				system("cls");
		
					if(userID.compare(username)==0 && pw.compare(password)==0){
						cout<<"Your Login was successful! Thank you.\n";
				
						menu();
					}
	
					else{
						cout<<"\nInvalid username or password!";
						menu();
					}
			}
			void regis(){
		
				string u_name; 
				string pass;
				cin.ignore();
				cout<<"Enter a username: ";
				getline(cin,u_name);
				cout<<"Enter a password upto 9 characters: ";
					for(int i=1; i<=9; i++)
				{
					words=getch();	
					cout<<"*";
					pass+=words;
				}
		
				username += u_name;
				password += pass;
				system("cls");
		
				cout<<"Your new email and password are set!";
				
				menu();
			}
			
};
int main(){
	
	registration r1;
	r1.menu();
	
	return 0;
}
	

