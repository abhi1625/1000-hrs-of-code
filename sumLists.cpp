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

void insert_at_tail(Node *&node, int data) {
    if (node == nullptr) {
        insert(node, data);
    }

    Node *newNode = new Node(data);
    node->next = newNode;
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

int numFromList(Node *list) {
    int i = 1;
    int num = list->data;
    while(list->next != nullptr) {
        list = list->next;
        num += std::pow(10,i) * list->data; 
        ++i;
    }
    return num;
}

Node * listFromNum(int num) {
    Node *list = nullptr;
    while(num > 0) {
        int digit = num%10;
        cout << digit << endl;
        num /= 10;
        insert(list, digit);
    }
    return list;
}

Node * sumLists(Node * &list1, Node * &list2) {
    Node *list3 = nullptr;
    Node *result = nullptr;

    int carry = 0;
    while(list1 != nullptr || list2 != nullptr) {
        int sum = list1->data + list2 ->data + carry;
        int digit = sum%10;
        carry = sum/10;
        insert(list3, digit);

        cout << sum << endl;
        cout << digit << endl;
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 != nullptr) {
        while (list1 != nullptr) {
            int sum = list1->data + carry;
            int digit = sum%10;
            carry = sum/10;
            insert(list3, digit);
            list1 = list1->next;
        }
    } else if (list2 != nullptr) {
        while (list2 != nullptr) {
            int sum = list2->data + carry;
            int digit = sum%10;
            carry = sum/10;
            insert(list3, digit);
            list2 = list2->next;
        }
    }
    while (carry != 0) {
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        insert(list3, digit);
    }
    while (list3 != nullptr) {
        insert(result, list3->data);
        list3 = list3->next;
    }
    delete(list3);
    return result;
}

int main() {
    Node *list1 = nullptr;
    Node *list2 = nullptr;
    for (int i=0; i<3; i++) {
        insert(list1, random_range(1, 9));
        insert(list2, random_range(1, 9));
    }
    printList(list1);
    printList(list2);
    
    Node *list3 = sumLists(list1, list2);
    printList(list3);
    delete(list1);
    delete(list2);
    delete(list3);
    return 0;
}