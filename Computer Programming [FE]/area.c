#include<iostream>
    using namespace std;
   int main()
     {
        int a,r,base,ht,s,b,l;
        cout<<"1-triangle\n 2-circle\n 3-square\n 4-rectangle\n"<<endl;
        cin>>a;

        switch(a)
        {
           case 1: cout<<"Enter the base and height\n"<<endl;
                   cin>>base>>ht;
                   cout<<"The area of triangle is"<<0.5*base*ht<<endl;
                   break;

           case 2: cout<<"Enter the radius of circle\n"<<endl;
                   cin>>r;
                   cout<<"The are of circle is"<<3.14*r*r<<endl;
                   break;

           case 3: cout<<"Enter the side of the square\n"<<endl;
                   cin>>s;
                   cout<<"The area of square is"<<s*s<<endl;
                   break;

           case 4: cout<<"Enter the length and breadth of rectangle\n"<<endl;
                   cin>>l>>b;
                   cout<<"The area of rectangle is"<<l*b<<endl;
                   break;

           default: cout<<"Invalid Input"<<endl;
        }
        return 0;
    }
