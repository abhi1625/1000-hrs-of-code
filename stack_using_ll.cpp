#include <iostream>
#include <stdlib.h>

class Node {
 public:
    int data;
    Node *next;
};

class Stack {
 private:
    Node *top;
 public:
    Stack(){top=NULL;}
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x) {
    Node *t = new Node;
    if (t == NULL) {
        std::cout << "Stack overflow" << std::endl;
    } else {
        t->data = x;
        t->next = this->top;
        this->top = t;
    }
}

int Stack::pop() {
    int x = -1;
    Node *t = top;
    if (this->top == NULL) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        x = top->data;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::Display() {
    Node *temp = top;
    for (int i=0; temp!=NULL;i++) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    std::cout << st.pop();
    st.Display();
    return 0;
}