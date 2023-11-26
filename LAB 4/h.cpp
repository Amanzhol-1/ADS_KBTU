#include <iostream>
#include <queue>

using namespace std;

int sum = 0;

struct Node {
    int value;
    Node *left, *right;
    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

struct BST {
    private:
        Node *root;

        Node* _insert(Node *node, int value) {
            if(!node) {
                return new Node(value);
            }
            if(node->value < value) {
                node->right = _insert(node->right, value);
            } else if(node->value > value) {
                node->left = _insert(node->left, value);
            }
            return node;
        }

        Node* _solve(Node *cur) {
            if(cur->right) _solve(cur->right);
            sum = cur->value = sum + cur->value;
            cout << cur->value << " ";
            if(cur->left) _solve(cur->left);
            return cur;
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        void solve() {
            root = _solve(this->root);
        }
};

int main() {
    int n; cin >> n;
    BST *tree = new BST();
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        tree->insert(x);
    }
    tree->solve();
    cout << "\n";

    return 0;
}