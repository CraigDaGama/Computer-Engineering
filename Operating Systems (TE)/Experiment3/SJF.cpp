//sjf
#include<iostream>
using namespace std;

int main()
{
     int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
    int p[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times
    int CT[n]; // Array to store completion times

   cout << "\nEnter burst times for each process:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Process " << i  << ": ";
        cin >> BT[i];
        p[i] = i + 1; // Initialize process numbers
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(BT[i]<BT[j])
                {
               swap(BT[i],BT[j]);
               swap(p[i],p[j]);

                }
        }
    }


   CT[1]=BT[1];

    for(int i=2;i<=n;i++)
    {
       CT[i]=CT[i-1]+BT[i];}

    for(int i=1;i<=n;i++)
    {
        WT[i]=CT[i]-BT[i];
        TT[i]=WT[i]+BT[i];
    }

    double TAWT = 0;
    double TATT = 0;
    for(int i=1;i<=n;i++)
    {
        TAWT=TAWT+WT[i];
        TATT=TATT+TT[i];
        }
      double  AWT=TAWT/n;
      double  ATT=TATT/n;


    cout<<"Process"<<"\t\t"<<"BT"<<"\t\t"<<"CT"<<"\t\t"<<"WT"<<"\t\t"<<"TT\n";
    for(int i=1;i<=n;i++)
    {
     cout<<"P"<<p[i]<<"\t\t"<<BT[i]<<"\t\t"<<CT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TT[i];
     cout<<"\n";
    }

    cout<<"\nThe average waiting time:"<<AWT<<"\n";
    cout<<"The average turnaround time:"<<ATT<<"\n";

    //Displaying the gantt chart
     cout<<"\n\nGantt chart:";
     for(int i=1; i<=n; i++)
     cout<<"P"<<p[i]<<" ";
    return 0;
}
