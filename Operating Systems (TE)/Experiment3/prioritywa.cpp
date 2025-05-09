#include<iostream>
using namespace std;

int main()
{
    int n; // Number of processes
    int time = 0, minPriority, k = 1;
    double TAWT = 0, TATT = 0, AWT, ATT;

    cout << "Enter the number of processes: ";
    cin >> n;

    int p[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int WT[n];// Array to store waiting times, initialized to 0
    int TT[n]; // Array to store turnaround times
    int CT[n]; // Array to store completion times
    int AT[n]; // Array to store arrival times
    int priority[n]; // Array to store priorities

    // Input burst times, arrival times, and priorities for each process
    for(int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Burst time: ";
        cin >> BT[i];
        cout << "Arrival time: ";
        cin >> AT[i];
        cout << "Priority: ";
        cin >> priority[i];
        p[i] = i + 1; // Initialize process numbers
    }

    // Sort processes by arrival time (if equal, by burst time)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(AT[j] > AT[j + 1] || (AT[j] == AT[j + 1] && BT[j] > BT[j + 1])) {
                swap(AT[j], AT[j + 1]);
                swap(BT[j], BT[j + 1]);
                swap(p[j], p[j + 1]);
                swap(priority[j], priority[j + 1]);
            }
        }
    }

    // Scheduling based on priority
    CT[0] = AT[0] + BT[0];
    time = CT[0];

    for(int i = 1; i < n; i++) {
        minPriority = priority[i];
        int minIndex = i;

        for(int j = i; j < n; j++) {
            if(AT[j] <= time && priority[j] < minPriority) {
                minPriority = priority[j];
                minIndex = j;
            }
        }

        // Swap the selected process to the current position
        swap(AT[i], AT[minIndex]);
        swap(BT[i], BT[minIndex]);
        swap(p[i], p[minIndex]);
        swap(priority[i], priority[minIndex]);

        // Update the time and calculate the completion time for the selected process
        time += BT[i];
        CT[i] = time;
    }

    // Calculate waiting time and turnaround time for each process
    for(int i = 0; i < n; i++) {
        WT[i] = CT[i] - AT[i] - BT[i];
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
    cout << "Process\tCT\tBT\tAT\tPrty\tWT\tTT" << endl;
    for(int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << CT[i] << "\t" << BT[i] << "\t" << AT[i] << "\t" << priority[i] << "\t" << WT[i] << "\t" << TT[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << AWT << endl;
    cout << "Average Turnaround Time = " << ATT << endl;

     //Displaying the gantt chart
     cout<<"\n\nGantt chart:";
     for(int i=0; i<n; i++)
     cout<<"P"<<p[i]<<" ";

    return 0;
}
