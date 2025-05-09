///Producer consumer problem to store n-1 elements in the buffer

#include<iostream>
using namespace std;

int buffersize, buffer[10], s = 1, Empty, full = 0, i, in = 0, out = 0, mutex = 1, next_produced, next_consumed, choice;

int wait(int s) {
    while(s < 0) {
        cout << "\n Buffer not accessible";
        return 0;
    }
    return s--;
}

int signal(int s) {
    return s++;
}

void produce() {
    Empty = wait(Empty);
    mutex = wait(mutex);
    if((in + 1) % buffersize == out) {
        cout << "\n Buffer is full";
    } else {
        cout << "\n enter item to be produced: ";
        cin >> next_produced;
        cout << "\n item produced is: " << next_produced;
        buffer[in] = next_produced;
        in = (in + 1) % buffersize;
    }
    mutex = signal(mutex);
    full = signal(full);
}

void consumer() {
    full = wait(full);
    mutex = wait(mutex);
    if(in == out) {
        cout << "\n Buffer is empty";
    } else {
        next_consumed = buffer[out];
        cout << "\n the item consumed is: " << next_consumed;
        out = (out + 1) % buffersize;
    }
    mutex = signal(mutex);
    Empty = signal(Empty);
}

int main() {
    cout << " \n Enter size of buffer: ";
    cin >> buffersize;
    int buffer[buffersize];
    Empty = buffersize;

    do {
        cout << "\n 1.Producer"<<"\t 2.Consumer"<<"\t 3.Exit: ";
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: produce();
                break;
            case 2: consumer();
                break;
            case 3: exit(1);
                break;
            default: cout << "\n Invalid input";
        }

    } while(choice != 3);
    return 0;
}
