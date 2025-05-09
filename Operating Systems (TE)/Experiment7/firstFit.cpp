//First Fit
#include <iostream>
using namespace std;

int main() {
    int pno, bno, psize[10], bsize[10], flag[10], allocation[10], i, j;

    cout << "Enter the number of processes: ";
    cin >> pno;

    cout << "Enter the number of blocks: ";
    cin >> bno;

    cout << "Enter the size of each process: ";
    for(i = 1; i <= pno; i++) {
        cin >> psize[i];
    }

    cout << "Enter the size of each block: ";
    for(i = 1; i <= bno; i++) {
        cin >> bsize[i];
    }

    for(i = 1; i <= bno; i++) {
        flag[i] = 0;
        allocation[i] = 1;
    }

    for(i = 1; i <= pno; i++) {
        for(j = 1; j <= bno; j++) {
            if(flag[j] == 0 && bsize[j] >= psize[i]) {
                allocation[j] = i;
                flag[j] = 1;
                break;
            }
        }
    }

    cout << "\nBlock no\tBlock size\tProcess no\tProcess size\n";
    for(i = 1; i <= bno; i++) {
        cout << "\nB" << i << "\t\t" << bsize[i];
        if(flag[i] == 1) {
            cout << "\t\tP" << allocation[i] << "\t\t" << psize[allocation[i]];
        } else {
            cout << "\t\tUnallocated";
        }
    }

    return 0;
}
