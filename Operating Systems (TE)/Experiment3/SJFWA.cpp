//SJF with Arrival
#include<iostream>
using namespace std;

int main()
{
    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    int temp, Min = 0, k = 1, sum = 0;
    int p[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int AT[n]; // Array to store arrival times
    int WT[n] = {0}; // Initialize waiting times to zero
    int TT[n] = {0}; // Initialize turnaround times to zero
    int CT[n]; // Array to store completion times
    int completed[n] = {0}; // Initialize as not completed

    // Input burst times and arrival times for each process
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Burst Time: ";
        cin >> BT[i];
        cout << "Arrival Time: ";
        cin >> AT[i];
        p[i] = i + 1; // Initialize process numbers
    }

    // Sort processes by arrival time
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(AT[j] > AT[j + 1]) {
                swap(AT[j], AT[j + 1]);
                swap(p[j], p[j + 1]);
                swap(BT[j], BT[j + 1]);
            }
        }
    }

    // Schedule the first process
    CT[0] = AT[0] + BT[0];

    // Schedule the remaining processes
    for(int i = 1; i < n; i++) {
        sum = CT[i - 1];
        Min = BT[i];
        int pos = i;

        for(int j = i; j < n; j++) {
            if(AT[j] <= sum && BT[j] < Min) {  // Fix: Check if process has arrived
                Min = BT[j];
                pos = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(AT[i], AT[pos]);
        swap(p[i], p[pos]);
        swap(BT[i], BT[pos]);

        // Calculate completion time
        CT[i] = sum + BT[i];
    }

    // Calculate waiting time and turnaround time
    for(int i = 0; i < n; i++) {
        WT[i] = CT[i] - AT[i] - BT[i];
        TT[i] = WT[i] + BT[i];
    }

    // Calculate average waiting time and average turnaround time
    double TAWT = 0;
    double TATT = 0;
    for(int i = 0; i < n; i++) {
        TAWT += WT[i];
        TATT += TT[i];
    }
    double AWT = TAWT / n;
    double ATT = TATT / n;

    // Display the results
    cout << "Process\tBT\t\tAT\t\tCT\t\tWT\t\tTT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << BT[i] << "\t\t" << AT[i] << "\t\t" << CT[i] << "\t\t" << WT[i] << "\t\t" << TT[i] << "\n";
    }

    cout << "\nThe average waiting time: " << AWT << "\n";
    cout << "The average turnaround time: " << ATT << "\n";

    cout<<"\nGantt chart :";
     for(int i=0; i<n; i++)
    cout<<"P"<<p[i]<<" ";

    return 0;
}
