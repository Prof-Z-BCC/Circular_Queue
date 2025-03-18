#include <iostream>

const int SIZE = 5;

using namespace std;

class Q {
public :
    int head,
        tail,
        used;
    
    int arr[SIZE];

    Q() { 
        head = 0;
        tail = 0;
        used = 0;
    }

    bool isEmpty() {
        if (used == 0) return true;
        return false;
    }

    bool isFull() {
        if (used == SIZE) return true;
        return false;
    }

    bool enqueue(int val) {
        if (this->isFull()) {
            cout << "Overflow" << endl;
            return false;
        }

        arr[tail] = val;
        tail = (tail + 1) % SIZE;
        used++;
        return true;
    }

    int dequeue() {
        if (this->isEmpty()) {
            cout << "Underflow." << endl;
            return -9999;
        }
        int val = arr[head];
        head = (head + 1) % SIZE;
        used--;
        return val;
    }

    int peekSize() {
        return used;
    }

    void print() {
        if (this->isEmpty()) {
            return;
        }

        for (int index = 0, loc = head; index < used; index++) {
            cout << arr[loc] << " ";
            loc = ((loc + 1) % SIZE);

        }
        cout << endl;
    }

};

int main() {
    Q q;
    q.enqueue(1);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(2);
    q.enqueue(4);
    q.print();
    q.enqueue(6);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(1);
    q.print();

    return 0;
}
