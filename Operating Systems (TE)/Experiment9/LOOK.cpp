#include <iostream>
#include <cmath>
#include <algorithm> // For sort()

using namespace std;

#define MAX 20  // Maximum number of requests

int main() {
    int currentHead, numOfReq, totalHeadMov = 0, movement;
    int requests[MAX];  // Array to store disk requests
    int seekSequence[MAX + 1];  // Array to store the sequence of requests visited

    // Input for number of requests and their values
    cout << "Enter the number of requests being serviced by the hard disk: ";
    cin >> numOfReq;

    cout << "Enter the requests: ";
    for (int i = 0; i < numOfReq; i++) {
        cin >> requests[i];
    }

    // Input for the current head position
    cout << "Enter the current head position: ";
    cin >> currentHead;

    // Input for the direction of movement
    cout << "1. Towards right\n2. Towards left\n";
    cin >> movement;

    // Sort the requests array to handle them in order
    sort(requests, requests + numOfReq);

    // Add the current head position to the sequence
    seekSequence[0] = currentHead;

    // Handle SCAN algorithm based on the movement direction
    if (movement == 1) {  // Moving towards right
        // First, move to the farthest right cylinder
        totalHeadMov += abs(currentHead - requests[numOfReq - 1]);
        currentHead = requests[numOfReq - 1];
        seekSequence[1] = currentHead;

        // Then, move left and serve the requests
        for (int i = numOfReq - 2; i >= 0; i--) {
            totalHeadMov += abs(currentHead - requests[i]);
            currentHead = requests[i];
            seekSequence[numOfReq - i] = currentHead;
        }
    } else if (movement == 2) {  // Moving towards left
        // First, move to the farthest left cylinder
        totalHeadMov += abs(currentHead - requests[0]);
        currentHead = requests[0];
        seekSequence[1] = currentHead;

        // Then, move right and serve the requests
        for (int i = 1; i < numOfReq; i++) {
            totalHeadMov += abs(currentHead - requests[i]);
            currentHead = requests[i];
            seekSequence[i + 1] = currentHead;
        }
    }

    // Output the seek sequence
    cout << "Seek Sequence: ";
    for (int i = 0; i <= numOfReq; i++) {
        cout << seekSequence[i];
        if (i != numOfReq) cout << " -> ";
    }
    cout << endl;

    // Output the total head movement
    cout << "The total head movement is " << totalHeadMov << endl;

    return 0;
}
