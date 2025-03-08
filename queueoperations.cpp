#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* rear; // Rear points to the last inserted node
public:
    CircularQueue() {
        rear = nullptr;
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear; // Point to itself
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* front = rear->next;
        if (rear == front) { // Only one node in the queue
            rear = nullptr;
        } else {
            rear->next = front->next;
        }
        cout << front->data << " dequeued.\n";
        delete front;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
        } else {
            cout << "Front element: " << rear->next->data << "\n";
        }
    }
};

int main() {
    CircularQueue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.getFront();
    
    q.dequeue();
    q.getFront();
    
    q.dequeue();
    q.dequeue();
    q.dequeue(); 
    
    return 0;
}