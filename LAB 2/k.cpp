#include <iostream>
#include <map> 

using namespace std;

struct Node {
    char val;
    Node* next;
    Node() {}
    Node(char val) {
        this->val = val;
        next = NULL;
    }
};

void push(Node* &end, Node* &head, int val) {
    if(end == NULL) {
        head = new Node(val);
        end = head;
        return;
    }
    end->next = new Node(val);
    end = end->next;
}


int main() {
    int n;
    cin >> n;
    
    while(n--) {
        int c;
        cin >> c;
        Node* head = nullptr;
        Node* end = head;
        map <char, int> m;
        while(c--) {
            char val;
            cin >> val;
            push(end, head, val);
            m[val]++;

            Node* cur = head;
            bool first = false;
            while(cur) {
                if(m[cur->val] == 1) {
                    first = true;
                    break;
                }
                cur = cur->next;
            }
            if(first) cout << cur->val << " ";
            else cout << -1 << " ";
        }
        m.clear();
        cout << endl;
    }
}