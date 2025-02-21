/*
Write a program to implement a class ‘Complex Nos’ with data members(real,imag).
Include parameterised and copy constructors to initialize data members and also
include members functions to compute and display the sum and difference of complex
nos.*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class Complex_Nos{
    public:
        float real, imag;
        Complex_Nos(){ /*do-nothing constructor*/}
        Complex_Nos(float r, float i){
            real=r;
            imag=i;
        }
        Complex_Nos(const Complex_Nos &c);
        Complex_Nos Sum(Complex_Nos c1, Complex_Nos c2){
            Complex_Nos SumRes;
            SumRes.real=c1.real+c2.real;
            SumRes.imag=c1.imag+c2.imag;
            return SumRes;
        }
        Complex_Nos Diff(Complex_Nos c1, Complex_Nos c2){
            Complex_Nos DiffRes;
            DiffRes.real=c2.real-c1.real;
            DiffRes.imag=c2.imag-c1.imag;
            return DiffRes;
        }
        void display();

};
Complex_Nos::Complex_Nos(const Complex_Nos &c){
    real=c.real;
    imag=c.imag;
}
void Complex_Nos::display(){
    cout<<real<<"+i("<<imag<<")"<<endl;
}
int main(){
    int c, t, r, i;
    Complex_Nos sum, diff;
    while(1){
        cout<<"\tWelcome to Complex Number Calculator\t\n";
        cout<<"1.Enter Values\n2.Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>c;
        switch(c){
            case 1:
            {
                cout<<"Enter real and imaginary value: ";
                cin>>r>>i;
                Complex_Nos a(r, i);
                Complex_Nos b(a);
                cout<<"Enter real and imaginary value: ";
                cin>>r>>i;
                a=Complex_Nos(r, i);
                do{
                    cout<<"\tOperation Calculator\t\n";
                    cout<<"1.Addition\n2.Subtraction\n3.Exit\n";
                    cout<<"Enter choice: ";
                    cin>>t;
                    switch(t){
                        case 1:
                            sum =sum.Sum(a, b);
                            cout<<"the sum is ";
                            sum.display();
                            break;
                        case 2:
                            diff=diff.Diff(a, b);
                            cout<<"The difference is ";
                            diff.display();
                            break;
                        case 3:
                            break;
                        default:
                            cout<<"Invalid Choice";
                            break;
                    }
                }while(t!=3);
            }
                break;
            case 2:
                exit(1);
            default:
                cout<<"Invalid Choice";
                break;
        }
    }
    return 0;
}
