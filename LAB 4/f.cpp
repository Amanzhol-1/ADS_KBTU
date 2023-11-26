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
            if(cur->value < value) {
                cur->right = _insert(cur->right, value);
            } else if(cur->value > value) {
                cur->left = _insert(cur->left, value);
            }
            return cur;
        }

        void _preorder(Node *cur) {
            if(!cur) {
                return ;
            }
            cout << cur->value << " ";
            _preorder(cur->left);
            _preorder(cur->right);
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        void preorder() {
            _preorder(this->root);
        }

        int solve() {
            int cnt = 0;
            queue <Node*> q;
            q.push(this->root);
            while(!q.empty()) {
                Node *cur = q.front();
                if(q.front()->left) q.push(cur->left);
                if(q.front()->right) q.push(cur->right);
                if(cur->left && cur->right) {
                    cnt++;
                }
                q.pop();
            }
            return cnt;
        }
};

int main() {
    int n; cin >> n;
    BST *tree = new BST();
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        tree->insert(x);
    }
    cout << tree->solve() << "\n";

    return 0;
}