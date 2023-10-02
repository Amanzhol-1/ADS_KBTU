#include <iostream>

using namespace std;

struct Node{ 
    int val; 
    Node* next; 

    Node(int val){ 
        this->val = val;
        this->next = nullptr;
    }
};

void nearestNumber(Node * head, int nearest){
    Node * cur = head;
    int answer = 0; int index = 0;
    int min = abs(nearest - head->val);
    while (cur != nullptr){
        if (min > abs(nearest - cur->val)){
            min = abs(nearest - cur->val);
            answer = index;
        }
        cur = cur-> next;
        index++;
    }
    cout << answer;
}

int main(){
    int n; cin >> n;
    Node * head; Node * cur;
    for (int i = 0; i < n; i++){
        int val; cin >> val;
        if (i == 0){
            head = new Node(val);
            cur = head;
        }
        else{
            cur -> next = new Node(val);
            cur = cur -> next;
        }
    }
    int nearest; cin >> nearest;
    nearestNumber(head, nearest);
}