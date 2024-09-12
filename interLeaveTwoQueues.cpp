#include <iostream>
#include <queue>
using namespace std;

void interLeave(queue<int> &org) {
    int n = org.size();
    queue<int> first;

    if (n%2 != 0) {
        cout << "this queue side is not EVEN. So, this code cannot interleave. \n";
        return;
    }

    for (int i=0; i<n/2; i++) {
        first.push(org.front());
        org.pop();
    }

    while(!first.empty()) {
        org.push(first.front());
        first.pop();
        org.push(org.front());
        org.pop();
    }
}

int main() {
    queue<int> q;

    // Example queue with even number of elements
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    interLeave(q);

    // Printing the interleaved queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;

 }
