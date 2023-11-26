#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;

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

        Node* _insert(Node *cur, int value) {
            if(!cur) {
                return new Node(value);
            }
            if(cur->value < value) {
                cur->right = _insert(cur->right, value);
            } else if(cur->value > value) {
                cur->left = _insert(cur->left, value);
            }
            return cur;
        }

        void _inorder(Node *cur) {
            if(!cur) {
                return;
            }
            _inorder(cur->left);
            v.push_back(cur->value);
            _inorder(cur->right);
        }

        void _preorder(Node *cur) {
            if(!cur) {
                return;
            }
            cout << cur->value << " ";
            _preorder(cur->left);
            _preorder(cur->right);
        }

        Node* _solve(int l, int r) {
            if(r < l) {
                return nullptr;
            }
            int mid = l + (r - l) / 2;
            Node* cur = new Node(v[mid]);
            cur->left = _solve(l, mid - 1);
            cur->right = _solve(mid + 1, r);
            return cur;
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        void inorder() {
            _inorder(root);
        }

        void preorder() {
            _preorder(root);
        }

        void solve(int l, int r) {
            root = _solve(l, r);
        }
};

int main() {
    int n; cin >> n;
    int size = pow(2, n) - 1;

    BST *tree = new BST();
    for(int i = 0; i < size; i++) {
        int x; cin >> x;
        tree->insert(x);
    }

    tree->inorder();
    tree->solve(0, size - 1);
    tree->preorder();

    return 0;
}