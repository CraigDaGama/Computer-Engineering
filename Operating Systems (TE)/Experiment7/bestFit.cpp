//Best Fit
#include <iostream>
using namespace std;

int main() {
    int pno, bno, psize[10], bsize[10], flag[10], allocation[10], i, j, temp, smallest = 999;

    cout << "\nEnter the number of processes: ";
    cin >> pno;

    cout << "\nEnter the number of blocks: ";
    cin >> bno;

    cout << "Enter the size of each process: ";
    for(i = 1; i <= pno; i++) {
        cin >> psize[i];
    }

    cout << "Enter the size for each block: ";
    for(i = 1; i <= bno; i++) {
        cin >> bsize[i];
    }

    for(i = 1; i <= bno; i++) {
        flag[i] = 0;
        allocation[i] = -1;
    }

    for(i = 1; i <= pno; i++) {
        for(j = 1; j <= bno; j++) {
            if(flag[j] != 1) {
                temp = bsize[j] - psize[i];
                if(temp >= 0) {
                    if(smallest > temp) {
                        allocation[i] = j;
                        smallest = temp;
                    }
                }
            }
        }
        flag[allocation[i]] = 1;
        smallest = 999;
    }

    cout << "\nProcess no\tProcess size\tBlock no\tBlock size";
    for(i = 1; i <= pno && allocation[i] != 0; i++) {
        cout << "\nP" << i << "\t\t" << psize[i] << "\t\tB" << allocation[i] << "\t\t" << bsize[allocation[i]];
    }

    return 0;
}

