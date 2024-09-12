#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int val) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){
        if(q1.empty()) {
            cout << "The Stack is EMPTY! \n";
            return;
        }
        q1.pop();
    }

    void top(){
        if(q1.empty()) {
            cout << "The Stack is EMPTY! \n";
            return;
        }
        cout << q1.front() << endl;
    }

    bool empty(){
        return q1.empty();
    }
};

int main() {
    Stack s;

    // Test Case 1: Basic Operations (Push, Pop, Top)
    s.push(10);
    s.push(20);
    s.push(30);
    s.top();  // Expected output: 30
    s.pop();
    s.top();  // Expected output: 20

    // Test Case 2: Handling Empty Stack
    Stack s2;
    s2.pop();  // Expected output: The Stack is EMPTY!
    s2.top();  // Expected output: The Stack is EMPTY!

    // Test Case 3: Sequential Push and Pop with Emptying
    s.push(1);
    s.push(2);
    s.push(3);
    s.top();  // Expected output: 3
    s.pop();
    s.top();  // Expected output: 2
    s.pop();
    s.top();  // Expected output: 1
    s.pop();
    s.pop();  // Expected output: The Stack is EMPTY!
    s.top();  // Expected output: The Stack is EMPTY!

    // Test Case 4: Push After Emptying Stack
    s.push(5);
    s.push(10);
    s.pop();
    s.pop();
    s.push(15);
    s.top();  // Expected output: 15

    return 0;
}