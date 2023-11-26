#include <iostream>
#include <vector>

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
        vector <int> levels;

        Node* _insert(Node* node, int value, int level) {
            if(!node) {
                if(level >= levels.size()) {
                    levels.push_back(value);
                } else {
                    levels[level] += value;
                }

                return new Node(value);
            }
            if(value < node->value) {
                node->left = _insert(node->left, value, ++level);
            } else if(value > node->value) {
                node->right = _insert(node->right, value, ++level);
            }
            return node;
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            int level = 0;
            root = _insert(root, value, level);
        }

        void solve() {
            cout << levels.size() << "\n";
            for(int i = 0; i < levels.size(); i++) {
                cout << levels[i] << " ";
            }
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

    return 0;
}