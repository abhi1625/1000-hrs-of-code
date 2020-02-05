#include<iostream>
#include<random>

using std::cout;
using std::endl;

// create linked-list
struct Node {
    int data;
    Node *next;
    Node(int d) : data{d}, next{nullptr} {} //constructor for a struct
};

//insert node at head
void insert(Node * &head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printList(Node *head) {
    while(head) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

static inline int random_range(const int min, const int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

void deleteNode(Node *node) {
    if (node == nullptr || node->next == nullptr) {
        return; 
    }
    Node *tempNode = node->next;
    node->data = tempNode->data;
    node->next = tempNode->next;
    delete tempNode;
}

int main() {
    Node *head = nullptr;
    for (int i=0; i<10; i++) {
        insert(head, random_range(1, 50));
    }
    printList(head);
    Node *ptr = head;
    for(int j=0; j<5; j++) {
        ptr = ptr->next;
    }
    deleteNode(ptr);
    printList(head);
    return 0;
}