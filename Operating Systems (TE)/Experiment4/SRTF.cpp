#include <iostream>
using namespace std;

int main() {

    int p[10];       // Array to store process numbers
    int BT[10];      // Array to store burst times
    int rem_BT[10];  // Array to store remaining burst times
    int WT[10];      // Array to store waiting time
    int TT[10];      // Array to store turnaround time
    int AT[10];      // Array to store arrival times
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
        rem_BT[i] = BT[i];  // Initialize remaining burst time as the burst time
        p[i] = i + 1;       // Initialize process numbers
    }

    rem_BT[9] = 999; // Assign a large value for comparison purposes

    // Loop until all processes are completed
    for (t = 0; count != n; t++) {
        small = 9; // Initialize small with a large value index (dummy process)

        // Find the process with the smallest remaining burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (AT[i] <= t && rem_BT[i] > 0 && rem_BT[i] < rem_BT[small]) {
                small = i;
            }
        }

        // Decrease the remaining burst time of the selected process
        rem_BT[small]--;

        // If the process is completed
        if (rem_BT[small] == 0) {
            CT = t + 1; // Calculate completion time
            WT[small] = CT - BT[small] - AT[small]; // Calculate waiting time
            TT[small] = BT[small] + WT[small];      // Calculate turnaround time
            count++;    // Increment the number of completed processes
        }
    }

    // Calculate total waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        TAWTT += WT[i];
        TATT += TT[i];
    }

    // Calculate average waiting time and turnaround time
    float AWT = TAWTT / n;
    float ATT = TATT / n;

    // Output the results
    cout << "Process" << "\t" << "BT" << "\t" << "AT" << "\t" << "WT" << "\t" << "TT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << BT[i] << "\t" << AT[i] << "\t" << WT[i] << "\t" << TT[i];
        cout << "\n";
    }

    // Output average times
    cout << "\nThe average waiting time: " << AWT << endl;
    cout << "The average turnaround time: " << ATT << endl;

    return 0;
}

