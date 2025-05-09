#include <iostream>
#include <algorithm>  // For sort()
#include <cmath>      // For abs()

using namespace std;

#define MAX 20  // Define the maximum number of requests

int main() {
    int currentHead, numOfReq, movement, totalHeadMov = 0;
    int lwrCyl, hghCyl;
    int requests[MAX];  // Array to store the requests

    cout << "Enter the lower cylinder number: ";
    cin >> lwrCyl;
    cout << "Enter the higher cylinder number: ";
    cin >> hghCyl;

    cout << "Enter the number of requests being serviced by the harddisk: ";
    cin >> numOfReq;

    cout << "Enter the requests: ";
    for (int i = 0; i < numOfReq; i++) {
        cin >> requests[i];
    }

    cout << "Enter the current head position: ";
    cin >> currentHead;

    cout << "1. Towards right\n2. Towards left\n";
    cout << "Enter the movement direction: ";
    cin >> movement;

    // Sort the requests array to handle them in order
    sort(requests, requests + numOfReq);

    cout << "Seek Sequence: " << currentHead;  // Output initial head position in sequence

    // Depending on the movement direction, calculate the total head movement and display sequence
    if (movement == 1) { // Moving towards right
        // Move to the farthest right cylinder first
        for (int i = 0; i < numOfReq; i++) {
            if (requests[i] >= currentHead) {
                totalHeadMov += abs(currentHead - requests[i]);
                currentHead = requests[i];
                cout << " -> " << currentHead;  // Output each step in sequence
            }
        }

        // Then move to the farthest right cylinder boundary
        if (currentHead != hghCyl) {
            totalHeadMov += abs(currentHead - hghCyl);
            currentHead = hghCyl;
            cout << " -> " << currentHead;
        }

        // Move left to serve remaining requests
        for (int i = numOfReq - 1; i >= 0; i--) {
            if (requests[i] <= currentHead) {
                totalHeadMov += abs(currentHead - requests[i]);
                currentHead = requests[i];
                cout << " -> " << currentHead;
            }
        }
    }
    else if (movement == 2) { // Moving towards left
        // Move to the farthest left cylinder first
        for (int i = numOfReq - 1; i >= 0; i--) {
            if (requests[i] <= currentHead) {
                totalHeadMov += abs(currentHead - requests[i]);
                currentHead = requests[i];
                cout << " -> " << currentHead;
            }
        }

        // Then move to the farthest left cylinder boundary
        if (currentHead != lwrCyl) {
            totalHeadMov += abs(currentHead - lwrCyl);
            currentHead = lwrCyl;
            cout << " -> " << currentHead;
        }

        // Move right to serve remaining requests
        for (int i = 0; i < numOfReq; i++) {
            if (requests[i] >= currentHead) {
                totalHeadMov += abs(currentHead - requests[i]);
                currentHead = requests[i];
                cout << " -> " << currentHead;
            }
        }
    }

    cout << "\nThe total head movement is " << totalHeadMov << endl;

    return 0;
}


