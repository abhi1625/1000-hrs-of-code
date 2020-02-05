#include <iostream>

struct Node {
    int data;
    Node * next;
};
class Queue {
 private:
    Node * front;
    Node * rear;
 public:
    Queue(){front = NULL; rear = NULL;}
    ~Queue() {delete front; delete rear;}
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x) {
    Node *t = new Node;
    if (t == NULL) {
        std::cout << "Queue is full" << std::endl;
    } else {
        t->data = x;
        t->next = NULL;
        if (front == NULL) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue() {
    int x = -1;

    if (front==NULL) {
        std::cout << "queue i empty" << std::endl;
    } else {
        x = front->data;
        Node * t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void Queue::Display() {
    Node * p = front;
    while(p != NULL) {
        std::cout << p->data << " -> ";
        p = p->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    q.dequeue();
    q.Display();

    return 0;
}
