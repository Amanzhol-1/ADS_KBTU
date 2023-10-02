#include <iostream>

using namespace std;

struct Node{
    int val; 
    int index;
    Node * next;

    Node(int val){
        this->val = val;
        this -> next = nullptr;
        this ->index = 0;
        
    }
};

void answer(Node * head){
    Node * cur = head;
    while(cur != nullptr){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
}

int main(){
    int n; cin >> n;
    Node * head; Node * cur;

    for (int i = 1; i <= n; i++){
        int val; cin >> val;
        if (i == 1){
            head = new Node(val);
            cur = head;
        }
        else if (i % 2 == 0) continue;
        else {
            cur -> next = new Node(val);
            cur = cur -> next;
        }
    }
   answer(head);
}