#include <iostream>
#include <random>
#include <memory>
using std::cout;
using std::cin;
using std::endl;

// Create a linked list
struct Node {
    int data = 0;
    //std::unique_ptr<Node> next = nullptr;
    Node *next = nullptr;
};
// helper function to insert elements to the front of a list
void insert(Node * &head, int data);
// helper funciton to display all elements of the linked list
void displayList(Node *head);
// helper function to generate random integers in a given range
static inline int random_range(const int min, const int max);

// remove dups method 1
// space complexity O(1)
//time complexity O(n^2)
void removeDups(Node *head) {
    if (head == nullptr || (head->next == nullptr)) {
        return;
    }
    Node *currNode = head;
    while(currNode) {
        Node *temp = currNode;
        while(temp->next != nullptr) {
            if (temp->next->data == currNode->data) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        currNode = currNode->next;
    }
}

// method 2 - using hash table
// space complexity - O(n)
// time complexity - O(n)
// void removeDups2(Node *head) {
//     if (head == nullptr || (head->next == nullptr)) {
//         return;
//     }

// }

int main() {

    Node *head = nullptr;
    for (int i=0; i<1; i++) {
        insert(head, random_range(1,10));
    }
    displayList(head);
    removeDups(head);
    displayList(head);

    return 0;
}







// helper function to insert elements to the front of a list
void insert(Node * &head, int data) {
    // std::unique_ptr<Node> newNode(new Node );
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// helper funciton to display all elements of the linked list
void displayList(Node *head) {
    while(head) {
        cout << head->data  << "-->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// helper function to generate random integers in a given range
static inline int random_range(const int min, const int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

