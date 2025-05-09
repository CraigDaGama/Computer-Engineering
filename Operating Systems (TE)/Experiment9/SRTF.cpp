#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int ch, n, tdm = 0, request[50], i, count = 0, index, dist;

    cout << "Enter the current head position: ";
    cin >> ch;

    cout << "Enter the number of requests to service: ";
    cin >> n;

    cout << "Enter the requests: ";
    for (i = 1; i <= n; i++) {
        cin >> request[i];
    }

    cout << "Seek Sequence: " << ch;  // Print the initial position

    while (count != n) {
        int min = 9999;

        // Find the closest request
        for (i = 1; i <= n; i++) {
            dist = abs(ch - request[i]);
            if (min > dist) {
                min = dist;
                index = i;
            }
        }

        // Update total disk head movement and the current position
        tdm += min;
        ch = request[index];
        request[index] = 9999;  // Mark this request as serviced
        count++;

        cout << " -> " << ch;  // Print each step in the seek sequence
    }

    cout << "\nTotal Disk Head Movement is: " << tdm << endl;
    return 0;
}
