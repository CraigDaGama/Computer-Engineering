//3.Preemptive Priority Scheduling
//(Lower number, higher priority)
#include <iostream>
using namespace std;
int main()
{
    int p[10];       // Array to store process numbers
    int BT[10];      // Array to store burst times
    int rem_BT[10];  // Array to store remaining burst times
    int WT[10];      // Array to store waiting time
    int TT[10];      // Array to store turnaround time
    int AT[10];      // Array to store arrival times
    int PR[10];      // Array to store the priorities
    int small;       // To choose the process with the smallest remaining burst time
    int CT;          // To store the completion time
    float TAWTT = 0; // Total Waiting Time
    float TATT = 0;  // Total Turnaround Time
    int t = 0;       // Current time
    int count = 0;   // Number of processes completed

    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    // Input burst times and arrival times for each process
    cout << "Enter burst times and arrival times for each process\n";
    for (int i = 0; i < n; i++) {
        cout << "Process: " << i + 1 << "\n";
        cout << "Burst Time: ";
        cin >> BT[i];
        cout << "Arrival Time: ";
        cin >> AT[i];
        cout<< "Priority: ";
        cin>> PR[i];
        rem_BT[i] = BT[i];  // Initialize remaining burst time as the burst time
        p[i] = i + 1;       // Initialize process numbers
    }
//Lower number higher priority
PR[9]=999;
for(t=0;count!=n;t++)
{
  small=9;
  for(int i=0;i<n;i++)
  {
	if(AT[i]<=t && rem_BT[i]>0 && PR[i]<PR[small]) //to find the process with less rem time
	{
 	small=i;
	}
  }
  rem_BT[small]--;
  if(rem_BT[small]==0)
  {
	CT=t+1;
	WT[small]=CT-BT[small]-AT[small];
	TT[small]=BT[small]+WT[small];
	count++;
   }
  }

  for(int i=0;i<n;i++)
 {
   TAWTT+=WT[i];
   TATT+=TT[i];
 }
 float AWT=TAWTT/n;
 float ATT=TATT/n;

 // Output the results
    cout << "Process" << "\t" << "BT" << "\t" << "AT" << "\t" <<"Priority" << " WT" << "\t" << "TT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << BT[i] << "\t" << AT[i] << "\t" << PR[i] << "\t " << WT[i] << "\t" << TT[i];
        cout << "\n";
    }

    // Output average times
    cout << "\nThe average waiting time: " << AWT << endl;
    cout << "The average turnaround time: " << ATT << endl;
	return 0;
}

