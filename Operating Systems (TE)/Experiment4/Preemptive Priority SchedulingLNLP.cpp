#include <iostream>
using namespace std;

int main() {
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
    int n;           // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter burst time, arrival time, and priority for each process\n";
    for (int i = 0; i < n; i++) {
        cout << "Process: " << i + 1 << "\n";
        cout << "Burst Time: ";
        cin >> BT[i];
        cout << "Arrival Time: ";
        cin >> AT[i];
        cout << "Priority: ";
        cin >> PR[i];
        rem_BT[i] = BT[i];
        p[i] = i + 1;
    }
    // Higher Number Higher Priority
    PR[9] = 0;
    while (count != n) {
        small = 9;
        for (int i = 0; i < n; i++) {
            if (AT[i] <= t && rem_BT[i] > 0 && PR[i] > PR[small]) {
                small = i;
            }
        }
        if (rem_BT[small] > 0) {
            rem_BT[small]--;
        }
        if (rem_BT[small] == 0) {
            CT = t + 1;
            WT[small] = CT - BT[small] - AT[small];
            TT[small] = BT[small] + WT[small];
            count++;
        }
        t++;
    }
    for (int i = 0; i < n; i++) {
        TAWTT += WT[i];
        TATT += TT[i];
    }
    float AWT = TAWTT / n;
    float ATT = TATT / n;

    // Output the results
    cout << "Process" << "\t" << "BT" << "\t" << "AT" << "\t" <<"Priority" << " WT" << "\t" << "TT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << BT[i] << "\t" << AT[i] << "\t" << PR[i] << "\t " << WT[i] << "\t" << TT[i];
        cout << "\n";
    }
    cout << "\nThe average WT: " << AWT << endl;
    cout << "The avg TT: " << ATT << endl;
    return 0;
}
