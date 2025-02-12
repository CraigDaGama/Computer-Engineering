#include <iostream>  
using namespace std;

int main() {
    int n, d, q, r;
    
    cout << "Enter the dividend: ";
    cin >> n;
    
    cout << "Enter the divisor: ";
    cin >> d;

    q = n / d;  // Quotient
    r = n % d;  // Remainder

    cout << "The quotient is: " << q << "\n";
    cout << "The remainder is: " << r << endl;

    return 0;
}
