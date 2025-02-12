#include <iostream>
#include "Grade.h"  

using namespace std;
using namespace Grade; 

int main() {
    int sub1, sub2, sub3, sub4, sub5, sub6;
    float p;
    string g; 
   
    cout << "Enter marks of the 1st Subject: ";
    cin >> sub1;
    cout << "Enter marks of the 2nd Subject: ";
    cin >> sub2;
    cout << "Enter marks of the 3rd Subject: ";
    cin >> sub3;
    cout << "Enter marks of the 4th Subject: ";
    cin >> sub4;
    cout << "Enter marks of the 5th Subject: ";
    cin >> sub5;
    cout << "Enter marks of the 6th Subject: ";
    cin >> sub6;
    
    p = percentage(sub1, sub2, sub3, sub4, sub5, sub6);
    g = grade(p);
   
    cout << "Percentage = " << p << "%" << endl;
    cout << "Grade = " << g << endl;

    return 0;
}
