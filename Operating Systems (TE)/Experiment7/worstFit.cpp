//Worst Fit
#include <iostream>
using namespace std;

int main() {
    int pno, bno, psize[10], bsize[10], flag[10], alloc[10], i, j, temp, largest = 0;

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
    }

    for(i = 1; i <= pno; i++) {
        alloc[i] = -1;
    }

    for(i = 1; i <= pno; i++) {
        for(j = 1; j <= bno; j++) {
            if(flag[j] != 1) {
                temp = bsize[j] - psize[i];
                if(temp >= 0) {
                    if(largest < temp) {
                        alloc[i] = j;
                        largest = temp;
                    }
                }
            }
        }

        flag[alloc[i]] = 1;
        largest = 0;
    }

    cout << "\nProcess no\tProcess size\tBlock no\tBlock size";
    for(i = 1; i <= pno; i++) {
        if(alloc[i] == -1) {
            cout << "\nP" << i << "\t\t" << psize[i] << "\t\tUnallocated\t\t";
        } else {
            cout << "\nP" << i << "\t\t" << psize[i] << "\t\tB" << alloc[i] << "\t\t" << bsize[alloc[i]];
        }
    }

    return 0;
}
