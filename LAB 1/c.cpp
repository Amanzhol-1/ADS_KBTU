#include <iostream>
#include <string> 
#include <stack>

using namespace std;

int main(){
    string s1, s2; cin >> s1 >> s2;
    stack <char> st1;
    stack <char> st2;

    for (int i = 0; i < s1.size(); i++){
        if (s1[i] == '#'){
            st1.pop();
        }
        else{
            st1.push(s1[i]);
        }
    }

    for (int i = 0; i < s2.size(); i++){
        if (s2[i] == '#'){
            st2.pop();
        }
        else {
            st2.push(s2[i]);
        }
    }

    if (st1 == st2){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}