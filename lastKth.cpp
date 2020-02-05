#include <iostream>
#include <random>

struct Node {
    int data;
    Node *next = nullptr;
};

void insert(Node * &head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void displayList(Node *head) {
    while(head) {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

static inline int random_range(const int min, const int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

int lastElem(Node * &head, int k) {
    if (head == nullptr) {
        return -1;
    }
    Node *ptr1 = head;
    Node *ptr2 = head;
    
    int i=0;
    while (i<k && (ptr2->next != nullptr)) {
        // std::cout << ptr2->data << std::endl;
        ptr2 = ptr2->next;
        ++i;
    }

    // out of bounds
    if (i < k) {
        return -1;
    }

    while(ptr2->next != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1->data;
}

int main() {
    Node *head = nullptr;
    for (int i=0; i<10; i++) {
        insert(head, random_range(1, 50));
    }
    displayList(head);
    int output = lastElem(head, 10);
    std::cout << "elem is " << output << std::endl;
    return 0;
}