#include<iostream>
using namespace std;

int main() {
    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
    int p[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times
    int CT[n]; // Array to store completion times

    // Input burst times for each process
    cout << "\nEnter burst times for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> BT[i];
        p[i] = i + 1; // Initialize process numbers
    }

    // Calculate completion time for each process
    CT[0] = BT[0]; // The first process's completion time is its burst time
    for (int i = 1; i < n; i++) {
        CT[i] = CT[i - 1] + BT[i];
    }

    // Calculate waiting time for each process
    WT[0] = 0; // The first process has 0 waiting time
    for (int i = 1; i < n; i++) {
        WT[i] = CT[i - 1]; // Waiting time is the completion time of the previous process
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        TT[i] = BT[i] + WT[i];
    }

    // Calculate average waiting time and average turnaround time
    double TWT = 0;
    double TTT = 0;
    for (int i = 0; i < n; i++) {
        TWT += WT[i];
        TTT += TT[i];
    }
    double AWT = TWT / n;
    double ATT = TTT / n;

    // Display the results, including averages
    cout << "\nProcess\t\tBT\t\tCT\t\tWT\t\tTT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t\t" << BT[i] << "\t\t" << CT[i] << "\t\t" << WT[i] << "\t\t" << TT[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << AWT;
    cout << "\nAverage Turnaround Time: " << ATT;

    //Displaying the gantt chart
     cout<<"\n\nGantt chart:";
     for(int i=0; i<n; i++)
     cout<<"P"<<p[i]<<" ";

    return 0;
}
