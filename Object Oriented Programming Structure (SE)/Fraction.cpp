 #include<iostream>
 using namespace std;

class fraction
   {
     public:
      int num,denom;

       void displayfraction()
         {
           cout<<num<<"/"<<denom;
         }
   };
int main()
{
  fraction f1;
  f1.num=3;
  f1.denom=4;
  f1.displayfraction();
  return 0;
}
