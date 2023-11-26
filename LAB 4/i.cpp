#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
    int multiplicity;
    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
        this->multiplicity = 1;
    }
};

struct BST {
    private:
        Node *root;

        Node* _insert(Node *node, int value) {
            if(!node) {
                return new Node(value);
            }
            if(value > node->value) {
                node->right = _insert(node->right, value);
            } else if(value < node->value) {
                node->left = _insert(node->left, value);
            } else if(value == node->value) {
                node->multiplicity++;
            }
            return node;
        }

        void _cnt(Node *cur, int target) {
            if(!cur) {
                cout << 0 << endl;
                return;
            }
            if(cur->value < target) {
                _cnt(cur->right, target);
            } else if(cur->value > target) {
                _cnt(cur->left, target);
            } else {
                cout << cur->multiplicity << "\n";
            }
            return;
        }
        
        void _remove(Node *cur, int x) {
            if(!cur) {
                return;
            }
            if(cur->value < x) {
                _remove(cur->right, x);
            } else if(cur->value > x) {
                _remove(cur->left, x);
            } else {
                if(cur->multiplicity > 0) {
                    cur->multiplicity--;
                }
            }
            return;
        }

        void _preorder(Node *node) {
            if(!node) {
                return;
            }
            cout << node->value << " : " << node->multiplicity << "\n";
            _preorder(node->left);
            _preorder(node->right);
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        void remove(int x) {
            _remove(root, x);
        }

        void cnt(int x) {
            _cnt(root, x);
        }

        void preorder() {
            _preorder(root);
        }
};

int main() {
    int q; cin >> q;
    BST *tree = new BST();
    while(q--) {
        string command;
        int x;
        cin >> command >> x;
        if(command == "insert") {
            tree->insert(x);
        } else if(command == "delete") {
            tree->remove(x);
        } else if(command == "cnt") {
            tree->cnt(x);
        }
    }

    return 0;
}