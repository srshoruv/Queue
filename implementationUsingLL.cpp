#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = tail = NULL;
    }
    void push(int val) {
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if (isEmpty()) {
            cout << "The queue is empty! \n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void front() {
        if (isEmpty()) {
            cout << "The queue is empty! \n";
            return;
        }
        cout << head->data << "\n";
    }

    bool isEmpty(){
        return head == NULL;
    }

};

int main() {
    Queue q;
    q.push(10);         // Queue: 10
    q.push(20);         // Queue: 10, 20
    q.push(30);         // Queue: 10, 20, 30
    
    q.front();          // Expected output: 10
    
    q.pop();            // Queue: 20, 30
    q.front();          // Expected output: 20
    
    q.pop();            // Queue: 30
    q.front();          // Expected output: 30

    q.pop();            // Queue: empty
    q.front();          // Expected output: "The queue is empty!"
    
    return 0;
}