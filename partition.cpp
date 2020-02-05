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

int main() {
    Node *head = nullptr;
    for (int i=0; i<3; i++) {
        insert(head, random_range(1, 50));
    }
    printList(head);
    
 
    return 0;
}