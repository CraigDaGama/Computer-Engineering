/*Write a program demonstrating use of destructrors.*/
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

class Student{
	int rollno;
	char name[30];
	char branch[30];;
	public:
		Student(){
			cout<<"A-Constructor\n";
		}
		Student(int r, char n[], char b[]);
		void display();
		~Student(){ //Destructor
			cout<<"A-Destructor\n";
		}
};
Student::Student(int r, char n[], char b[]){
	rollno =r;
	strcpy(name, n);
	strcpy(branch, b);
}
void Student::display(){
	cout<<"Roll No: "<<rollno<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Branch: "<<branch<<endl;
}
int main(){
	int r;
	char n[30], b[30];
	Student s;
	cout<<"Enter Roll No: ";
	cin>>r;
	cout<<"Enter name: ";
	cin>>n;
	cout<<"Enter branch: ";
	cin>>b;
 	s=Student(r, n, b);
	s.display();
	return 0;
	
}
