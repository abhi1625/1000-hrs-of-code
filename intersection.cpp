#include <iostream>
#include <random>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

/**
 * [printList Helper routine to print list]
 * @param head [head of the list]
 */
void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

int listLen(Node * list){
    int len = 0;
    while(list != nullptr) {
        len += 1;
        list = list->next;
    }
    return len;
}

Node * intersection(Node *&list1, Node *&list2) {
    int len1 = listLen(list1);
    int len2 = listLen(list2);

    Node * ptr1 = (len1 > len2) ? list1 : list2;
    Node * ptr2 = (len1 > len2) ? list2 : list1;

    int i = 0;
    while(i < std::abs(len1 - len2) && ptr1 != nullptr) {
        ptr1 = ptr1->next;
        ++i;
        std::cout << i << std::endl;
    }

    
    // std::cout << ptr2 << std::endl;
    while(ptr1 && ptr2) {
        if (ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    delete(ptr1);
    delete(ptr2);
    return nullptr;
}


int main()
{
  Node * list1 = new Node(3);
  list1->next = new Node(6);
  list1->next->next = new Node(9);
  list1->next->next->next = new Node(12);
  list1->next->next->next->next = new Node(15);
  list1->next->next->next->next->next = new Node(18);

  Node * list2 = new Node(7);
  list2->next = new Node(10);
  list2->next->next = list1->next->next->next;

  printList(list1);
  printList(list2);
  Node * res = intersection(list1, list2);
  if (res == nullptr) std::cout << "No intersection \n";
  else std::cout << "intersection is at " << res << std::endl;

  delete(list1);
  delete(list2);
  delete(res);
  return 0;
}