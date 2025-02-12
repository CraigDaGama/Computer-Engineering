#include <iostream>  
using namespace std;

int main() {
    int x, n, p, i;
    
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Enter the limit: ";
    cin >> x;

    for (i = 1; i <= x; i++) {  
        p = n * i;
        cout << n << " * " << i << " = " << p << endl;
    }

    return 0;
}
