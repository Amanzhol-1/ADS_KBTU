#include <iostream>

using namespace std;

struct Node{
    string s;
    Node * next;

    Node(string s){
        this->s = s;
        this->next = nullptr;
    }
};

Node* cyclicShift(Node * head, int k){
        Node * cur = head;
        Node * tail;
        while(cur -> next != nullptr){
            cur = cur-> next;
            tail = cur;
        }
        while(k--){
            Node *tmp = head -> next;
            tail -> next = head;
            head -> next = NULL;
            head = tmp;
            tail = tail->next;
        }
        return head;
    }

void answer(Node * head){
    Node * cur = head;
    while(cur != nullptr){
        cout << cur-> s << " ";
        cur = cur -> next;
    }
}



int main(){
    int n; cin >> n; int k; cin >> k;
    Node * head; Node * cur; 

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        if (i == 0){
            head = new Node(s);
            cur = head;
        }
        else{
            cur ->next = new Node(s);
            cur = cur -> next;
        }
    }
    head = cyclicShift(head, k);
    answer(head);
    
}