#include <iostream>
using namespace std;

int knapSack(int cap, int wt[], int profit[], int n) {
    int k[n + 1][cap + 1];

    // Build the table in bottom-up fashion
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (j < wt[i - 1])
                k[i][j] = k[i - 1][j];
            else
                k[i][j] = max(k[i - 1][j - wt[i - 1]] + profit[i - 1], k[i - 1][j]);
        }
    }

    // Now, trace back to find the items included in the knapsack
    int i = n, j = cap;
    cout<<"\nIncluded items:";
    while (i > 0 && j > 0){
        if (k[i][j] != k[i - 1][j]) {
            cout <<i << " ";
            j -= wt[i - 1];
            i--;
        } else {
            i--;
        }
    }

    return k[n][cap]; // Return the maximum profit
}

int main() {
    int profit[10], wt[10];
    int C, n;

    cout << "\nEnter the capacity: ";
    cin >> C;

    cout << "\nEnter the total number of elements: ";
    cin >> n;

    cout << "\nEnter the profit: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "\nEnter the weight: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout<<"\nitem \t weight \t profit"<<endl;
    for(int i=0;i<n;i++)
        cout<<i+1<< "\t"<< wt[i] << "\t\t"<<profit[i]<<endl;


    int maxProfit = knapSack(C, wt, profit, n);
    cout << "\nThe maximum profit is " << maxProfit << endl;

    return 0;
}
