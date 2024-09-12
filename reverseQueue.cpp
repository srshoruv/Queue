#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int> &q) {
    stack<int> st;

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> q;

    // Adding some test elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Reverse the queue
    reverse(q);

    // Output the reversed queue
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}