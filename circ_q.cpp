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
        if (head == tail) return true;
        return false;
    }

    bool isFull() {
        if ((tail + 1) % SIZE == head) return true;
        return false;
    }

    bool enqueue(int val) {
        if (this->isFull()) {
            cout << "Overflow" << endl;
            return false;
        }

        cout << "Head: " << head << " Tail: " << tail << endl;

        arr[tail] = val;
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

        for (int index = head; index < tail; index = ((index + 1) % SIZE)) {
            cout << arr[index] << " ";

        }
     //   cout << arr[tail] << endl;
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
    cout << "Used: " << q.peekSize() << endl;
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    cout << "Used: " << q.peekSize() << endl;
    q.enqueue(1);
    cout << "Used: " << q.peekSize() << endl;
    q.print();


}
