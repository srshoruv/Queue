#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int val) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }

    void front(){
        if(empty()) {
            cout << "The Queue is EMPTY! \n";
            return;
        }
        cout << s1.top() << endl;
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.front();  // Expected output: 10
    q.pop();
    q.front();  // Expected output: 20
    q.pop();
    q.front();  // Expected output: 30
    q.pop();
    q.front();  // Expected output: The Queue is EMPTY!

    return 0;
}