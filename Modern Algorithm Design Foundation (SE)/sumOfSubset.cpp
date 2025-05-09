#include <iostream>
#include <vector>
using namespace std;
// Define the function for sum of subset problem
void sumOfSubset(vector<int>& w, int s, int k, int r, int m, vector<int>& x) {
    if (s == m) {
        cout << "Subset found: ";
        for (int i = 0; i < k; ++i) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << endl;
        return;
    }

    if (k == w.size() || s > m || s + r < m) {
        return;
    }

    x[k] = 1;
    if (s + w[k] == m) {
        cout << "Subset found: ";
        for (int i = 0; i <= k; ++i) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << endl;
    } else if (s + w[k] < m) {
        sumOfSubset(w, s + w[k], k + 1, r - w[k], m, x);
    }

    x[k] = 0;
    sumOfSubset(w, s, k + 1, r - w[k], m, x);
}

int main() {
    // Input set elements from user
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> weights(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Input target sum from user
    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> x(weights.size(), 0); // Initialize x with zeros
    int totalSum = 0;
    for (int weight : weights) {
        totalSum += weight;
    }

    // Call the function
    sumOfSubset(weights, 0, 0, totalSum, targetSum, x);

    return 0;
}











