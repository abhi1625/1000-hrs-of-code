#include <iostream>

class Queue {
 private:
    int size;
    int front;
    int rear;
    int * q;
 public:
    Queue() {front = rear = -1;size=10;q = new int[size];}
    Queue(int size) {front=rear=-1;this->size=size; q = new int[size];}

    void enqueue(int x);
    int dequeue();
    void Display();

    ~Queue() {delete this->q;}
};

void Queue::enqueue(int x) {
    if (rear==size-1) {
        std::cout << "queue is full" << std::endl;
        return;
    } else {
        this->rear++;
        this->q[this->rear] = x;
    }
}

void Queue::Display() {
    for(int i=this->front+1; i!=this->rear+1;i++) {
        std::cout << q[i] << " "; 
    }
    std::cout << std::endl;
}

int Queue::dequeue() {
    int x = -1;
    if (this->rear == this->front) {
        std::cout << "The queue is empty" << std::endl;
    } else {
        this->front++;
        x = this->q[this->front];
    }
    return x;
}

int main() {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);

    q.Display();
    q.dequeue();
    q.Display();
    return 0;
}