#include <iostream>
using namespace std;

class Queue{
    int* arr;
    int capacity;
    int currSize;
    int f,r;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int val){
        if(currSize==capacity) {
            cout << "The Queue is FULL! \n";
            return;
        }
        
        r = (r+1) % capacity;
        arr[r] = val;
        currSize++;
    }

    void pop() {
        if(isEmpty()) {
            cout << "The Queue is EMPTY! \n";
            return;
        }
        f = (f+1)% capacity;
        currSize--;
    }

    void front(){
        if(isEmpty()) {
            cout << "The Queue is EMPTY! \n";
            return;
        }
        cout << arr[f] << endl;
    }

    bool isEmpty(){
        return currSize == 0;
    }

};

int main() {
    Queue q(3);          // Create a queue with capacity 3
    
    // Push elements and test the front
    q.push(10);          // Queue: 10
    q.push(20);          // Queue: 10, 20
    q.push(30);          // Queue: 10, 20, 30
    q.front();           // Expected output: 10
    
    // Pop elements and test the front
    q.pop();             // Queue: 20, 30
    q.front();           // Expected output: 20
    
    q.pop();             // Queue: 30
    q.front();           // Expected output: 30

    q.pop();             // Queue: empty
    q.front();           // Expected output: "The Queue is EMPTY!"

    return 0;
}