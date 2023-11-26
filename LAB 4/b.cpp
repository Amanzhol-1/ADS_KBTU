#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *right, *left;
    Node(int value) {
        this->value = value;
        this->right = this->left = nullptr;
    }
};

struct BST {
    private:
        Node *root;

        Node* _insert(Node *cur, int value) {
            if(!cur) {
                return new Node(value);
            }
            if(value > cur->value) {
                cur->right = _insert(cur->right, value);
            } else if(value < cur->value) {
                cur->left = _insert(cur->left, value);
            }
            return cur;
        }

        Node* _search(Node *cur, int target) {
            if(!cur) {
                return nullptr;
            }
            if(cur->value == target) {
                return cur;
            } else if(cur->value > target) {
                return _search(cur->left, target);
            } else {
                return _search(cur->right, target);
            }
        }

        int _getSize(Node *node) {
            if(!node) {
                return 0;
            }
            return _getSize(node->left) + _getSize(node->right) + 1;
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            this->root = _insert(root, value);
        }

        Node* search(int target) {
            return _search(root, target);
        }

        int getSize(Node *node) {
            return _getSize(node);
        }
};

int main() {
    int n, target;
    cin >> n;
    BST *tree = new BST();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree->insert(x);
    }
    cin >> target;
    Node *targetNode = tree->search(target);
    cout << tree->getSize(targetNode) << "\n";

    return 0;
}