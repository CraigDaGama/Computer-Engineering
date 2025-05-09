#include <iostream>
#include <cmath>
#define MAX 30
using namespace std;

int main() {
    int sequenceSize;
    int current;
    int sequence[MAX];
    int totalHeadMovement = 0;
    int displacement;

    cout << "Enter the Start Position: ";
    cin >> current;

    cout << "Enter the number of reads: ";
    cin >> sequenceSize;

    cout << "Enter the Sequence: ";
    for (int i = 1; i <= sequenceSize; i++) {
        cin >> sequence[i];
    }

    sequence[0] = current;
    sequenceSize++; // Increase the sequence size to account for the starting position

    cout << "Scheduling Sequence: " << sequence[0] << " ";
    for (int i = 1; i < sequenceSize; i++) {
        displacement = abs(sequence[i] - sequence[i - 1]);
        totalHeadMovement += displacement;
        cout << sequence[i] << " ";
    }

    cout << "\nTotal Head Movement = " << totalHeadMovement << endl;
    return 0;
}



