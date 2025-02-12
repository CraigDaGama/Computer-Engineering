#include <iostream>
using namespace std;

int main() {
    int i, n, a[100];    
   
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter the sorted array elements:" << endl;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (n % 2 == 0) {        
        float median = (a[n/2 - 1] + a[n/2]) / 2.0;
        cout << "The Median is the average of values at index " << (n/2 - 1)
             << " and " << n/2 << " with a value of " << median << endl;
    } else {        
        cout << "The Median is at index " << n/2 << " with a value of " << a[n/2] << endl;
    }

    return 0;
}
