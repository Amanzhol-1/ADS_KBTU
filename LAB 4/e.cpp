#include <iostream>
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
            return cur;
        }

        void _insert(Node *cur, int x, int y, int z) {
            if(!cur) {
                return;
            }
            if(cur->value == x) {
                if(z == 0) {
                    cur->left = new Node(y);
                    return;
                } else {
                    cur->right = new Node(y);
                    return;
                }
            }
            _insert(cur->left, x, y, z);
            _insert(cur->right, x, y, z);
        }

        int _solve(Node *cur, int max) {
            queue <Node*> q;
            q.push(cur);
            while(!q.empty()) {
                int size = q.size();
                if(max < size) {
                    max = size;
                }
                for(int i = 0; i < size; i++) {
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            return max;
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        void insert(int x, int y, int z) {
            _insert(root, x, y, z);
        }

        int solve(int max) {
            return _solve(root, max);
        }
};

int main() {
    int n; cin >> n;
    BST *tree = new BST();
    for(int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(i == 0) {
            tree->insert(x);
        }
        tree->insert(x, y, z);
    }
    cout << tree->solve(-1) << "\n";

    return 0;
}