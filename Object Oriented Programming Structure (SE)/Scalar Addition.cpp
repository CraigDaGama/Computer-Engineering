#include<iostream>
 using namespace std;

 1
 class Number
  {
    int a[50],n;

    public:
     void initArray()
      {
        cout<<"Enter the number of elements";
          cin>>n;
         for (int i=0; i<n; i++)
           {
             cin>>a[i];
           }
      }

     void ScalarAdd(int x)
      {
        for (int i=0; i<n; i++)
          {
            a[i]=a[i]+x;
          }
      }

     void displayarray()
      {
        for (int i=0; i<n; i++)
         {
           cout<<a[i]<<"\t";
         }
      }
  };

    int main()
     {
       Number n1;
       int x;
       n1.initArray();
       cout<<"Enter no. for scalar Addition"<<endl;
         cin>>x;
       n1.ScalarAdd(x);
       n1.displayarray();
       return 0;
     }
