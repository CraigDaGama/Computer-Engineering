#include<iostream>
using namespace std;

int main() {

    int n; // Number of processes
    double TAWT = 0, TATT = 0, AWT, ATT;

    cout << "Enter the number of processes: ";
    cin >> n;

    int p[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times
    int CT[n]; // Array to store completion times
    int priority[n]; // Array to store priorities

    // Input burst times and priorities for each process
    for(int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Burst time: ";
        cin >> BT[i];
        cout << "Priority: ";
        cin >> priority[i];
        p[i] = i + 1; // Initialize process numbers
    }

    // Sort processes by priority (higher priority comes first)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(priority[i] > priority[j]) {
                swap(BT[i], BT[j]);
                swap(p[i], p[j]);
                swap(priority[i], priority[j]);
            }
        }
    }

    // Calculate completion time for each process
    CT[0] = BT[0];
    for(int i = 1; i < n; i++) {
        CT[i] = CT[i - 1] + BT[i];
    }

    // Calculate waiting time and turnaround time for each process
    for(int i = 0; i < n; i++) {
        WT[i] = CT[i] - BT[i];
        TT[i] = WT[i] + BT[i];
    }

    // Calculate total waiting time and total turnaround time
    for(int i = 0; i < n; i++) {
        TAWT += WT[i];
        TATT += TT[i];
    }

    // Calculate average waiting time and average turnaround time
    AWT = TAWT / n;
    ATT = TATT / n;

    // Display the results
    cout << "\nProcess\t\tBT\t\tCT\t\tWT\t\tTT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t\t" << BT[i] << "\t\t" << CT[i] << "\t\t" << WT[i] << "\t\t" << TT[i] << "\n";
    }

    cout << "\nAWT = " << AWT << endl;
    cout << "ATT = " << ATT << endl;

     //Displaying the gantt chart
     cout<<"\n\nGantt chart:";
     for(int i=0; i<n; i++)
     cout<<"P"<<p[i]<<" ";

    return 0;
}
