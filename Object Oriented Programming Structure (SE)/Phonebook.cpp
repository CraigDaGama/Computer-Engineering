/*Write a program to implement a class called Phonebook. It should contain the contact name and
contact number and include member functions to initialize the data members (use setter and getter
functions). Use an array of object to display contact list.*/

#include<iostream>
#include<string>
using namespace std;
class phonebook
    {
        int number;
        string name;

        public:
        void setcontactno(int no) {number=no;}
        void setname(string s) {name=s;}

        string getname() {return name;}
        int getcontactno() {return number;}

    };

int main()
    {
        phonebook s[10];

        cout<<"Enter the number of contacts"<<endl;
        int n;
        cin>>n;
        string name;
        int no,m1,m2,m3;
        for (int i=0;i<n;i++)
      {
            cout<<"Enter contact name, contact number"<<endl;
            cin>>name>>no;
            s[i].setcontactno(no);
            s[i].setname(name);


      }

        for(int i=0;i<n;i++)
         {
           cout<<"contact name: "<<s[i].getname()<<endl;
          cout<<"contact number: "<<s[i].getcontactno()<<endl;
         }
    }
