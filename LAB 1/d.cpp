#include <iostream>
#include <stack>

using namespace std;

bool Balance(string s){
    stack <char> st;

    for (int i = 0; i < s.size(); i++){
        if (!st.empty() and st.top() == s[i]){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main(){
    string s; cin >> s;

    if (Balance(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

}