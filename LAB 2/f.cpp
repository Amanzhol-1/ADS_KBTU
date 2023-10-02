#include <iostream>

using namespace std;   


struct Node {
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    } 
};

void print(Node* head) {
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

void insert (Node *&head, int value, int pos) {
    Node *cur = head;
    Node *newNode = new Node(value);
    int i = 0;
    while (cur != NULL) {
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            break;
        }  
        if (i == pos - 1) {
            newNode -> next = cur->next;
            cur -> next = newNode;
            break;
        }
        cur = cur ->next;
        i++;
    }
}


int main () {
    int a;
    cin >> a;
    Node *head;
    Node *cur;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            head = new Node(x);
            cur = head;
        } else {
            cur -> next = new Node(x);
            cur = cur -> next;
        }
    }
    int value; cin >> value;
    int pos; cin >> pos;
    insert (head, value, pos);
    print (head);
}