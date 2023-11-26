#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

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
            cout << cur->value << " ";
            _inorder(cur->right);
        }

        int _maxDepth(Node *node) {
            if(!node) {
                return 0;
            }
            int leftDepth = _maxDepth(node->left);
            int rightDepth = _maxDepth(node->right);
            return max(leftDepth, rightDepth) + 1;
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

        int maxDistance() {
            queue <Node*> q;
            int result = -1;
            q.push(this->root);
            while(!q.empty()) {
                Node *cur = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                int distance = _maxDepth(q.front()->left) + _maxDepth(q.front()->right) + 1;
                result = max(result, distance);
                q.pop();
            }
            return result;
        }
};

int main() {
    int n;
    cin >> n;
    BST *bst = new BST();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst->insert(x);
    }
    cout << bst->maxDistance() << "\n";

    return 0;
}