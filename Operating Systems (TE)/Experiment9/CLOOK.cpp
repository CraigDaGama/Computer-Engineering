#include <iostream>
#include <cmath>
using namespace std;

#define MAX 20

int main() {
    int currentHead, requests[MAX], totalHeadMov = 0, numOfReq, temp, movement = -1;
    int minCyl, maxCyl;
    int seekSequence[MAX + 1];  // Array to store the sequence of head movements

    cout << "Enter the number of requests being serviced by the hard disk: ";
    cin >> numOfReq;

    cout << "Enter the requests: ";
    for (int i = 0; i < numOfReq; i++) {
        cin >> requests[i];
    }

    cout << "Enter the current head position: ";
    cin >> currentHead;

    cout << "1. Towards right\t2. Towards left: ";
    cin >> movement;

    // Add the current head position to the request array
    requests[numOfReq] = currentHead;
    numOfReq++;

    // Sort the requests array (using bubble sort in this case)
    for (int i = 0; i < numOfReq; i++) {
        for (int j = 0; j < numOfReq - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    minCyl = requests[0];    // Minimum cylinder
    maxCyl = requests[numOfReq - 1]; // Maximum cylinder

    // Find the current position index in the sorted request array
    int currentIndex;
    for (int i = 0; i < numOfReq; i++) {
        if (requests[i] == currentHead) {
            currentIndex = i;
            break;
        }
    }

    // Initialize the seek sequence with the starting head position
    seekSequence[0] = currentHead;

    // Calculate total head movement based on direction
    if (movement == 1) {  // Moving towards right
        // First, move to the rightmost position
        totalHeadMov = abs(currentHead - maxCyl);
        seekSequence[1] = maxCyl;  // Add the rightmost position to the sequence

        // Then, move to the leftmost position
        totalHeadMov += abs(maxCyl - minCyl);
        seekSequence[2] = minCyl;  // Add the leftmost position to the sequence

        // Finally, move to the next request (if any) that is in the sorted list
        for (int i = currentIndex + 1; i < numOfReq; i++) {
            totalHeadMov += abs(requests[i] - requests[i - 1]);
            seekSequence[i + 1] = requests[i];
        }
    } else {  // Moving towards left
        // First, move to the leftmost position
        totalHeadMov = abs(currentHead - minCyl);
        seekSequence[1] = minCyl;  // Add the leftmost position to the sequence

        // Then, move to the rightmost position
        totalHeadMov += abs(minCyl - maxCyl);
        seekSequence[2] = maxCyl;  // Add the rightmost position to the sequence

        // Finally, move to the previous request (if any) that is in the sorted list
        for (int i = currentIndex - 1; i >= 0; i--) {
            totalHeadMov += abs(requests[i] - requests[i + 1]);
            seekSequence[numOfReq - i] = requests[i];
        }
    }

    // Output the seek sequence
    cout << "Seek Sequence: ";
    for (int i = 0; i < numOfReq; i++) {
        cout << seekSequence[i];
        if (i != numOfReq - 1) cout << " -> ";
    }
    cout << endl;

    // Output the total head movement
    cout << "The total head movement is: " << totalHeadMov << endl;

    return 0;
}
