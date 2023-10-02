#include <iostream>
#include <map>

using namespace std;

map <int, int> m;
int max_cnt = 0;

struct Node {
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    } 
};

void mode(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        m[cur->val]++;
        max_cnt = max(max_cnt, m[cur->val]);
        cur = cur->next;
    }
}

void print(Node* head) {
  Node* cur = head;
  while (cur != nullptr) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main () {
    int n; cin >>n;
    Node *head; Node *cur;
    for (int i = 0; i < n; i++) {
        int val;cin >>val;
        if (i == 0) {
            head = new Node(val);
            cur = head;
        } else {
            cur -> next = new Node(val);
            cur = cur -> next;
        }
    }
    mode(head);
    map <int, int>::reverse_iterator it = m.rbegin();
    for(it; it != m.rend(); it++) {
        if(it->second == max_cnt) {
            cout << it->first<< " ";
        }
    }
}