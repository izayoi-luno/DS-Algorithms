// 红黑树
// Red Black Tree

#include <iostream>
#include <memory>

using namespace std;

enum Color { RED, BLACK };

template <typename T>
struct Node {
    T data;
    Color color;
    shared_ptr<Node> left, right, parent;

    Node(T data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class RedBlackTree {
private:
    shared_ptr<Node<T>> root;
    shared_ptr<Node<T>> TNULL;

    void initializeNULLNode(shared_ptr<Node<T>> node, shared_ptr<Node<T>> parent) {
        node->data = 0;
        node->color = BLACK;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = parent;
    }

    void preOrderHelper(shared_ptr<Node<T>> node) {
        if (node != TNULL) {
            cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        } 
    }

    void inOrderHelper(shared_ptr<Node<T>> node) {
        if (node != TNULL) {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        } 
    }

    void postOrderHelper(shared_ptr<Node<T>> node) {
        if (node != TNULL) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout << node->data << " ";
        } 
    }

    shared_ptr<Node<T>> searchTreeHelper(shared_ptr<Node<T>> node, T key) {
        if (node == TNULL || key == node->data) {
            return node;
        }

        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        } 
        return searchTreeHelper(node->right, key);
    }

    void fixDelete(shared_ptr<Node<T>> x) {
        shared_ptr<Node<T>> s;
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    } 

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    } 

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            } 
        }
        x->color = BLACK;
    }

    void rbTransplant(shared_ptr<Node<T>> u, shared_ptr<Node<T>> v){
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left){
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteNodeHelper(shared_ptr<Node<T>> node, T key) {
        shared_ptr<Node<T>> z = TNULL;
        shared_ptr<Node<T>> x, y;
        while (node != TNULL){
            if (node->data == key) {
                z = node;
            }

            if (node->data <= key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (z == TNULL) {
            cout << "Couldn't find key in the tree" << endl;
            return;
        } 

        y = z;
        Color y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (y_original_color == BLACK){
            fixDelete(x);
        }
    }
    
    void fixInsert(shared_ptr<Node<T>> k){
        shared_ptr<Node<T>> u;
        while (k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;	
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;

                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;	
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = BLACK;
    }

    void printHelper(shared_ptr<Node<T>> root, string indent, bool last) {
        if (root != TNULL) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "   ";
            } else {
                cout << "L----";
                indent += "|  ";
            }
            
            string sColor = root->color ? "BLACK" : "RED";
            cout << root->data << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    shared_ptr<Node<T>> minimum(shared_ptr<Node<T>> node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    void leftRotate(shared_ptr<Node<T>> x) {
        shared_ptr<Node<T>> y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(shared_ptr<Node<T>> x) {
        shared_ptr<Node<T>> y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

public:
    RedBlackTree() {
        TNULL = make_shared<Node<T>>(0);
        TNULL->color = BLACK;
        root = TNULL;
    }

    void preOrder() {
        preOrderHelper(this->root);
    }

    void inOrder() {
        inOrderHelper(this->root);
    }

    void postOrder() {
        postOrderHelper(this->root);
    }

    shared_ptr<Node<T>> searchTree(T k) {
        return searchTreeHelper(this->root, k);
    }

    shared_ptr<Node<T>> minimum() {
        return minimum(this->root);
    }

    void insert(T key) {
        shared_ptr<Node<T>> node = make_shared<Node<T>>(key);
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        shared_ptr<Node<T>> y = nullptr;
        shared_ptr<Node<T>> x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent == nullptr){
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        fixInsert(node);
    }

    void deleteNode(T data) {
        deleteNodeHelper(this->root, data);
    }

    void printTree() {
        if (root) {
            printHelper(this->root, "", true);
        }
    }
};

int main() {
    RedBlackTree<int> bst;
    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    bst.printTree();
    cout << endl << "After deleting" << endl;
    bst.deleteNode(40);
    bst.printTree();
    return 0;
}
