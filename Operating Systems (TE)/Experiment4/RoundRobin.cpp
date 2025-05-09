#include<iostream>
using namespace std;

int main()
{
    int n; // Number of processes
    int TS;//Time slice
    cout << "Enter the number of processes: ";
    cin >> n;
    cout<<"\nEnter the time slice: ";
    cin>>TS;

    int p[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int Rem_BT[n]; // Array to store remaining Burst times
    int WT[n]; // Array to store Waiting time
    int TT[n]; // Array to store Turnaround time
    float TWATT=0;
    float TATT=0;
    int T=0;   //Time to help count the CT
    float AWT, ATT;
    bool flag;//Process has finished or not

    // Input burst times and arrival times for each process
    cout << "Enter burst times and arrival times for each process:\n";
    for (int i = 1; i <=n; i++) {
        cout << "Process " << i << ":\n";
        cout << "Burst Time: ";
        cin >> BT[i];
        Rem_BT[i] = BT[i];
        p[i] = i + 1; // Initialize process numbers
    }
    while(1)
    {
     flag=true; //Then BT is not zero
     for(int i=1; i<=n;i++)
     {
      if(Rem_BT[i]> 0)
      {
      flag=false;
      if(Rem_BT[i]>TS)
      {
       T=T+TS;
       Rem_BT[i]=Rem_BT[i]-TS;
      }
      else{
       T=T+Rem_BT[i];
       Rem_BT[i]=0;
       WT[i]=T-BT[i];
      }
     }
    }
    if(flag==true) //If the burst time has Become 0
    {
     break;
    }
  }
  for(int i=1;i<=n;i++)
  {
   TT[i]=WT[i]+BT[i];
   TWATT += WT[i];
   TATT += TT[i];
  }


	cout<<"Process\t \tBT\t \tWT\t \tTT"<<endl;
	for(int i=1;i<=n;i++)
	{
    	cout<<"P"<<p[i]<<"\t\t"<<BT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TT[i]<<endl;
	}

	cout<<"\nTWATT = "<< TWATT/n<<endl;
	cout<<"TATT = "<< TATT/n;

    return 0;
}
