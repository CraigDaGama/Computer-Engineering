#include <iostream>
using namespace std;

int main() {
    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
    int processes[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int AT[n]; // Array to store arrival times
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times
    int CT[n]; //Array to store completion time

    // Input burst times and arrival times for each process
    cout << "Enter burst times and arrival times for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Burst Time: ";
        cin >> BT[i];
        cout << "Arrival Time: ";
        cin >> AT[i];
        processes[i] = i + 1; // Initialize process numbers
    }

    // Sort processes based on arrival times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (AT[j] > AT[j + 1]) {
                swap(AT[j], AT[j + 1]);
                swap(BT[j], BT[j + 1]);
                swap(processes[j], processes[j + 1]);
            }
        }
    }

    // Perform FCFS scheduling
    int currentTime = 0; // Initialize the current time
    for (int i = 0; i < n; i++) {
        if (AT[i] > currentTime) {
            currentTime = AT[i];
        }
        WT[i] = currentTime - AT[i];
        TT[i] = WT[i] + BT[i];
        currentTime += BT[i];

        // Calculate completion time for each process
       CT[0] = BT[0]; // The first process's completion time is its burst time
       for (int i = 1; i < n; i++) {
        CT[i] = CT[i - 1] + BT[i];
    }
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

    // Display the results including averages
    cout << "\nProcess\t\tBT\t\tCT\t\tWT\t\tTT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i] << "\t\t" << BT[i] << "\t\t" << CT[i] << "\t\t" << WT[i] << "\t\t" << TT[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << AWT << "\n";
    cout << "Average Turnaround Time: " << ATT << "\n";

    //Displaying the gantt chart
     cout<<"\n\nGantt chart:";
     for(int i=0; i<n; i++)
     cout<<"P"<<processes[i]<<" ";

    return 0;
}
