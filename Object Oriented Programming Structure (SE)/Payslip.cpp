/*Create two classes employee and payscale in an external namespace stored in a user defined header
file ‘payslip.h’. Assume necessary data members and use setter and getter function to initialize and
retrieve data member values. Use an array of object to display the payslip of each employee.*/

#include<iostream>
#include<string>
#include"payslip.h"
using namespace payslip;
using namespace std;
int main()
{
    employee s[10];
    cout<<"Enter the number of employees"<<endl;
    int n;
    cin>>n;
    string emp;
    int r,m1,m2,m3;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter employee name, payslip"<<endl;
        cin>>emp>>r;
        s[i].setpay(r);
        s[i].setname(emp);
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nEmployee Name: "<<s[i].getname()<<endl;
        cout<<"Payslip: "<<s[i].getpay()<<endl;
    }
}
