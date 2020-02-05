#include <iostream>
#include <queue>
using namespace std;

class Node {
 public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree {
 public:
    Node *root;
    Tree(){root=NULL;}
    void createTree();
    void preOrder(){preOrder(root);}
    void preOrder(Node *p);
    void postOrder(){postOrder(root);}
    void postOrder(Node *p);
    void inOrder(){inOrder(root);}
    void inOrder(Node *p);
    void levelOrder(Node *p);
    int height(Node *root);
};

void Tree::createTree() {
    Node *p, *t;
    int x;
    queue<Node*> Q;

    // define root node for the tree
    root = new Node;
    cout << "Enter root " << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    Q.push(root);

    while(!Q.empty()) {
        p = Q.front();
        Q.pop();

        // input left child
        cout << "enter lchild of " <<p->data << endl;
        cin >> x;
        if (x!=-1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            Q.push(t);
        }
        // input right child
        cout << "enter rchild of " << p->data << endl;
        cin >> x;
        if (x!=-1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            Q.push(t);
        }

    }
}

void Tree::preOrder(Node *p) {
    if (p) {
        cout << p->data;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::inOrder(Node * p) {
    if(p) {
        inOrder(p->lchild);
        cout << p->data;
        inOrder(p->rchild);
    }
}

void Tree::postOrder(Node * p) {
    if (p) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data;
    }
}

// breadth first traversal
void Tree::levelOrder(Node * p) {
    cout << p->data;
    queue<Node *> Q;
    Q.push(p);

    while(!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p->lchild) {
            cout << p->lchild->data;
            Q.push(p->lchild);
        }
        if (p->rchild) {
            cout << p->rchild->data;
            Q.push(p->rchild);
        }
    }
}

int Tree::height(Node * root) {
    int x=0, y=0;
    if(root==0) {
        return 0;
    }
    x=height(root->lchild);
    y=height(root->rchild);
    if (x>y) {
        return x+1;
    } else {
        return y+1;
    }
}

int main() {
    Tree t;
    t.createTree();
    // t.preOrder(t.root);
    // t.postOrder(t.root);
    // t.levelOrder(t.root);
    cout <<"heeight of the tree is " << t.height(t.root);
    return 0;
}