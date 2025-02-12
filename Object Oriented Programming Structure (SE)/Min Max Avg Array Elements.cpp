#include <iostream>
using namespace std;

int main() {
    int a[50], i, n;
    float sum = 0, avg;
        
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter the array elements:" << endl;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
   
    int minimum = a[0];
    int maximum = a[0];
    
    for (i = 0; i < n; i++) {
        if (a[i] > maximum)
            maximum = a[i];
        if (a[i] < minimum)
            minimum = a[i];

        sum += a[i];
    }

    avg = sum / n;  
   
    cout << "The minimum value is " << minimum 
         << ", the maximum value is " << maximum 
         << ", and the average value is " << avg << endl;

    return 0;
}
