 #include<iostream>
  using namespace std;
   int main()
     {
        int age;
        cout<<"Enter the age:"<<endl;
        cin>>age;
        if(age>=0&&age<=12)
        {
            cout<<"Child"<<endl;
        }
        else if(age>12&&age<18)
        {
            cout<<"Teen"<<endl;
        }
        else if(age>=18&&age<60)
        {
            cout<<"Adult"<<endl;
        }
        else if(age>=60)
        {
            cout<<"Senior Citizen"<<endl;
        }
        else
            cout<<"Invalid input"<<endl;
        return 0;
    }
