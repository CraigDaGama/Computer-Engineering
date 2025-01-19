// C++ program to demonstrate accessing of data members
#include <iostream>
using namespace std;
class Phonebook {
    // Access specifier
public:
    // Data  Members
    string contactname;
    int contactnum;
    // Member Functions()
    void printname() { cout << "contact name is :" <<contactname<<endl; }
    void printnum() { cout << "contact number is :" <<contactnum<<endl; }
};
int main()
{
    // Declare an object of class geeks
    Phonebook c1;
    // accessing data member
    c1.contactname = "craig";
    c1.contactnum = 1234567892;
    // accessing member function
    c1.printname();
    c1.printnum();
    return 0;
}
