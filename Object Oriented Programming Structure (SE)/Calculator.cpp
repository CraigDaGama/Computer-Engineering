// Create a class called ‘calculator’ which implements basic arithmetic operations.

#include<iostream>
#include<stdlib.h>
using namespace std;
class Calculator{
	float a, b;
	public:
		void setOp(int x, int y);
		void add();
		void sub();
		void mul();
		void div();
};
void Calculator::add(){
	float sum = a+b;
	cout<<"the sum is "<<sum<<endl;
}
void Calculator::sub(){
	float diff = a-b;
	cout<<"the difference is "<<diff<<endl;
}
void Calculator::mul(){
	float mul = a*b;
	cout<<"the product is "<<mul<<endl;
}
void Calculator::div(){
	float quo = a/b;
	cout<<"the quotient is "<<quo<<endl;
}
void Calculator::setOp(int x, int y){a=x; b=y;}
int main(){
	Calculator z;
	int a, b;
	int c;
	char g;
	while(1){
		cout<<"\t\tWelcome to Calculator\t\t"<<endl;
		cout<<"X. Enter numbers\nY. Exit"<<endl;
		cin>>g;
		switch(g){
		case 'X':
			cout<<"Enter 2 numbers: ";
			cin>>a>>b;
			z.setOp(a,b);
			cout<<"Enter the Operations to be performed\n1.Addition\t\t2.Subtraction\n3.Multiplication\t4.Division\n5.Exit"<<endl;
			cout<<"Enter choice: ";
			cin>>c;
			switch(c){
				case 1:
					z.add();
					break;
				case 2:
					z.sub();
					break;
				case 3:
					z.mul();
					break;
				case 4:
					z.div();
					break;
				default:
					cout<<"Invalid Choice"<<endl;
					break;
					}
				break;
			case 'Y':
				exit(1);
			default:
				cout<<"Invalid Choice"<<endl;
			}
		}

	return 0;
}
