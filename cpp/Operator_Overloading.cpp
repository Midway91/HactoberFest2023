//This code is written by ANURAG VISHWAKARMA
//GitHub: https://github.com/vishanurag/
//Portfolio: https://vishanurag.github.io/


#include<iostream>
using namespace std;

//complex class
class complex {
	float real, img;

	public:
	complex() {
		real = img = 0;
	}		
	complex(float x) {
		real = img = x;
	}
	complex(float x, float y) {
		real = x;
		img = y;
	}
	
	complex operator+(complex);
	complex operator*(complex);
	complex operator/(complex);
	void show();
	friend istream& operator>>(istream &in, complex &X);
	friend ostream& operator<<(ostream &out, complex &X);
};

//Overloading + operator with class complex objects...
complex complex::operator+(complex y) {
	complex Z;
	Z.real = real + y.real;
	Z.img = img + y.img;
	
	return Z;	
}

//Overloading / operator with class complex objects...
complex complex::operator/(complex y) {
	complex Z;
	float denominator = ((y.real * y.real) + (y.img * y.img));
	Z.real = ((real * y.real) + (img * y.img))/denominator;
	Z.img = ((y.real * img) - (real * y.img))/denominator;
	
	return Z;
}

//Overloading * operator with class complex objects...
complex complex::operator*(complex y) {
	complex Z;
	Z.real = ((real * y.real) - (img * y.img));
	Z.img = ((real * y.img) + (y.real * img));
	
	return Z;
}

//A normal show member function of class complex to display result...
void complex::show() {
	if(img > 0) cout<< " "<< real << " + " << img << "i \n";
	else cout<< " "<< real << img << "i \n";
}

//Overloading the cin<< of istream with complex class object...
istream& operator>>(istream &in, complex &X) {
	cout<<" Enter Real Part: ";
	in>>X.real;
	cout<<" Enter Img Part: ";
	in>>X.img;
	return in;
}

//Overloading the cout<< of ostream with complex class object...
ostream& operator<<(ostream &out, complex &X) {
	if(X.img > 0) out<< " "<< X.real << " + " << X.img << "i \n";
	else out<< " "<< X.real << X.img << "i \n";
	out<<" Operator Overloaded...\n";
	return out;
}

int main() {                               
	complex A, B, C, D, E;
	
	cout<<"\n Enter details of A: \n";
	cin>>A;
	cout<<"\n Enter details of B: \n";
	cin>>B;
	
	cout<< "\n A is: \n";
	cout<<A;
	cout<< " B is: \n";
	cout<<B;
	
	cout<< "\n Adding A & B : \n";
	C = A + B;
	cout<<C;
	
	cout<< "\n Dividing A with B : \n";
	D = A / B;
	cout<<D;
	
	cout<< "\n Multiplying A with B : \n";
	E = A * B;
	cout<<E;
	
	return 0;
}
