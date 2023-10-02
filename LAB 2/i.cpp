#include <iostream>
#include <cmath>
using namespace std;

struct Node {
  string value;
  Node* next;
  int cnt;

  Node() {}

  Node(string value) {
    this->value = value;
    this->next = NULL;
    cnt = 1;
  }
};

class LinkedList{
    int size;
public:
    Node * head;
    LinkedList(){
        head = NULL;
    }

    void add_front(string book){
        Node * cur = head;
        Node * newNode = new Node(book);
        if(head == NULL){
            newNode->next = head;
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        cout << "ok" << endl;
    }


    void add_back(string book){
        Node * cur = head;
        Node * newNode = new Node(book);
        if(head == NULL){
            head = newNode;
            cout << "ok" << endl;
        }
        else{
            while(cur != NULL){
                if(cur->next == NULL){
                    cur->next = newNode;
                    cout << "ok" << endl;
                    return;
                }
                cur = cur->next;
            }
        }
    }


    void erase_front(){
        if(head == NULL){
            cout << "error" << endl;
        }
        else{
            cout << head->value << endl;
            head = head->next;
        }
    }


    void erase_back(){
        if(head == NULL){
            cout << "error" << endl;
        }
        else if(head->next == NULL){
            cout << head->value << endl;
            head = NULL;
        }
        else if(head != NULL && head->next != NULL){
            Node * cur = head;
            Node * prev = head;
            while(cur != NULL){
                if(cur->next == NULL){
                    cout << cur->value << endl;
                    prev->next = NULL;
                    return;
                }
                prev = cur;
                cur = cur->next;
            }
        }
    }


    void front(){
        if(head == NULL){
            cout << "error" << endl;
        }
        else{
            cout << head->value << endl;
        }
    }


    void back(){
        if(head == NULL){
            cout << "error" << endl;
        }
        else{
            Node * cur = head;
            while(cur != NULL){
                if(cur->next == NULL){
                    cout << cur->value << endl;
                }
                cur = cur->next;
            }
        }
    }


    void clear(){
        head = NULL;
        cout << "ok" << endl;
    }


};

int main() {
    LinkedList list;
    while(1){
        string s; cin >> s;
        if(s == "add_front"){
            string book; cin >> book;
            list.add_front(book);
        }
        else if(s == "add_back"){
            string book; cin >> book;
            list.add_back(book);
        }
        else if(s == "erase_front"){
            list.erase_front();
        }
        else if(s == "erase_back"){
            list.erase_back();
        }
        else if(s == "front"){
            list.front();
        }
        else if(s == "back"){
            list.back();
        }
        else if(s == "clear"){
            list.clear();
        }
        else if(s == "exit"){
            cout << "goodbye";
            break;
        }
    }
}