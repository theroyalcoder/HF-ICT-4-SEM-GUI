#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    Node(int value) : left(0), right(0), value(value) {}
    Node *left;
    Node *right;
    int value;
};

class BinaryTree {
private:
    Node *root;
    void insert(int value, Node* node) {
        if (node->value < value) {
            // insert right
            if (node->right == 0) node->right = new Node(value);
            else insert(value, node->right);
        } else {
            // insert left
            if (node->left == 0) node->left = new Node(value);
            else insert(value, node->left);
        }
    }

public:
    BinaryTree() : root(0) {}
    void insert(int value) {
        if (root == 0) {
            root = new Node(value);
        } else {
            insert(value, root);
        }
    }
    int sum;
    int sumEven();
    int sumEven2(Node *);


};

int BinaryTree::sumEven() {
    return sumEven2(this->root);
}

int BinaryTree::sumEven2(Node *n) {

    if(n->value % 2 == 0) {
        //gerade
        sum += n->value;
    }

    if (n->left != nullptr) {
        sumEven2(n->left);
    }

    if(n->right != nullptr){
        sumEven2(n->right);
    }

    return sum;
}

int main(int argc, char **argv) {
    BinaryTree bt ;
    bt.insert (9);
    bt.insert (4);
    bt.insert (6);
    bt.insert (3);
    bt.insert (5);
    bt.insert (8);

    int sum = bt.sumEven(); // = 18

    cout << sum;

    return 0;
}
