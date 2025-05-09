#include <iostream>
#include <cmath>
using namespace std;

#define MAX 20

int main() {
    int currentHead, requests[MAX], totalHeadMov = 0, numOfReq, temp, visited[MAX], movement = -1;
    int lwrCyl, hghCyl, min, max;

    cout << "Enter the lower cylinder number: ";
    cin >> lwrCyl;
    cout << "Enter the higher cylinder number: ";
    cin >> hghCyl;

    cout << "Enter the number of requests being serviced by the harddisk: ";
    cin >> numOfReq;
    cout << "Enter the requests: ";
    for (int i = 0; i < numOfReq; i++) {
        cin >> requests[i];
        visited[i] = 0;
    }

    cout << "Enter the current head position: ";
    cin >> currentHead;
    cout << "1. Towards right\n2. Towards left" << endl;
    cin >> movement;

    // Adding the current head position to the request queue
    requests[numOfReq] = currentHead;
    numOfReq++;

    // Sort requests to handle them in order
    for (int i = 0; i < numOfReq; i++) {
        for (int j = 0; j < numOfReq - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Finding the current head's position in the sorted request list
    int headIndex = 0;
    for (int i = 0; i < numOfReq; i++) {
        if (requests[i] == currentHead) {
            headIndex = i;
            break;
        }
    }

    cout << "Seek Sequence: ";

    // Calculate total head movement based on C-SCAN direction
    if (movement == 1) { // Moving towards the right
        // Print the head's initial position
        cout << currentHead;

        // Move from current head to highest cylinder (right end)
        totalHeadMov += abs(currentHead - hghCyl);
        currentHead = hghCyl;
        cout << " -> " << currentHead;

        // Jump to the lowest cylinder
        totalHeadMov += abs(hghCyl - lwrCyl);
        currentHead = lwrCyl;
        cout << " -> " << currentHead;

        // Continue from the lowest to the first request on the left side of the head
        for (int i = 0; i < numOfReq; i++) {
            if (requests[i] > currentHead) {
                totalHeadMov += abs(currentHead - requests[i]);
                currentHead = requests[i];
                cout << " -> " << currentHead;
            }
        }
    }
    else if (movement == 2) { // Moving towards the left
        // Print the head's initial position
        cout << currentHead;

        // Move from current head to lowest cylinder (left end)
        totalHeadMov += abs(currentHead - lwrCyl);
        currentHead = lwrCyl;
        cout << " -> " << currentHead;

        // Jump to the highest cylinder
        totalHeadMov += abs(hghCyl - lwrCyl);
        currentHead = hghCyl;
        cout << " -> " << currentHead;

        // Continue from the highest to the last request on the right side of the head
        for (int i = numOfReq - 1; i >= 0; i--) {
            if (requests[i] < currentHead) {
                totalHeadMov += abs(currentHead - requests[i]);
                currentHead = requests[i];
                cout << " -> " << currentHead;
            }
        }
    }

    cout << "\nThe total head movement is " << totalHeadMov << endl;
    return 0;
}
