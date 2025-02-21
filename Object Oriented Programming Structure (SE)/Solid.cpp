/*
Write a program to implement a class ‘Solid’ with data members (radius,height).
Include different constructors to initialize data members and also include members
functions to compute volume of cylinder and cone. Include default argument for the
data member ‘radius’.*/
#include<iostream>
#include<stdlib.h>
#define PI 3.14159
using namespace std;

class Solid{
	double radius, height;
	public:
		Solid(){ }
		Solid(float h, float r);
		void VolCyl();
		void VolCon();
};
Solid::Solid(float h, float r=10){
	radius =r; height=h;
}
void Solid::VolCyl(){
	float vol= PI*radius*radius*height;
	cout<<"Volume of Cylinder is: "<<vol<<endl;
}
void Solid::VolCon(){
	float vol= PI*radius*radius*height*(0.33);
	cout<<"Volume of Cone is: "<<vol<<endl;
}
int main(){
	int c, t;
	Solid s;
	double r, h;
	while(1){
		cout<<"\t\tWelcome to Solid Calculator\t\t\n";
		cout<<"1. Enter dimensions\t2.Exit\nEnter choice: ";
		cin>>c;
		switch(c){
			case 1:
				cout<<"Enter Height and Radius: ";
				cin>>h>>r;
				s=Solid(h);
				do{
					cout<<"\t\tWelcome to Box Calculator\t\t\n";
					cout<<"1.Volume of Cylinder\n2.Volume of Cone\n3.Exit to menu"<<endl;
					cout<<"Enter choice: ";
					cin>>t;
					switch(t){
						case 1:
							s.VolCyl();
							break;
						case 2:
							s.VolCon();
							break;
						case 3:
							break;
						default:
							cout<<"Invalid choice"<<endl;
							break;
					}
				}while(t!=3);
				break;
			case 2:
				exit(1);
			default:
				cout<<"Invalid Choice"<<endl;
				break;
		}
	}
	return 0;
}
