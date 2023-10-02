#include <iostream>
#include <map>
using namespace std;

struct Node {
    string val;
    Node *next;

    Node(string val) {
        this->val = val;
        this->next = NULL;
    } 
    Node () { 
    }
};

void print(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
  }
}

void duplicate(Node* head) {
    Node *cur = head;
    Node *prev = head;

    while (cur != NULL) {
        if (cur->val == prev->val) {
            prev->next = cur->next;
        } else {
            prev -> next = cur;
            prev = prev->next;
        }
        cur = cur->next;
    }
}

int getCount(Node* head) {
    Node * cur = head;
    int cnt = 0;
    while (cur != NULL) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->val = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}


int main () {
int n; cin >>n;
Node *head = NULL;
string val;
for (int i = 0; i < n; i++) {
cin >>val;
    push(&head, val);
}

duplicate (head);
cout << "All in all: "<< getCount(head) << endl;
cout << "Students:"<< endl;
print(head);


}