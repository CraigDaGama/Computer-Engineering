#include <iostream>
#include <algorithm>  // For min() function
using namespace std;

int main() {
    int a, b, c;
    
    cout << "Enter any 3 numbers: ";
    cin >> a >> b >> c;

    int smallest = min(a, min(b, c));
    cout << smallest << " is the minimum" << endl;

    return 0;
}
