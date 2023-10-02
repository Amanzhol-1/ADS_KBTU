#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> b; 
    deque<int> n;
    int cnt = 0;

    for (int i = 0; i < 5; i++){
        int x; cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < 5; i++){
        int x; cin >> x;
        n.push_back(x);
    }

    while(!b.empty() and !n.empty() and cnt != 1000000){
        int nu = n.front();
        int bo = b.front();
        n.pop_front();
        b.pop_front();
        cnt++;
        if (nu == 0 and bo == 9){
            n.push_back(bo);
            n.push_back(nu);
        }
        else if (nu == 9 and bo == 0){
            b.push_back(bo);
            b.push_back(nu);
        }
        else if (nu > bo){
            n.push_back(bo);
            n.push_back(nu);
        }
        else{
            b.push_back(bo);
            b.push_back(nu);
        }
    }
    
    if (!b.empty()){
        cout << "Boris " << cnt; 
    }
    else if(!n.empty()) {
        cout << "Nursik " << cnt;
    }
    else {
        cout << "blin nichya";
    }
}