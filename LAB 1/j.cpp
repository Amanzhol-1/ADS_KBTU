#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque <int> d;
    char c;
    int n;

    while(cin >> c){
        if (c == '+'){
            cin >> n;
            d.push_front(n);
        }
        else if (c == '-'){
            cin >> n;
            d.push_back(n);
        }
        else if (c == '*'){
            if (d.empty()){
                cout << "error" << endl;
            }
            else{
                cout << d.front() + d.back() << endl;
                if (d.size() == 1) d.pop_back();
                else {
                    d.pop_front();
                    d.pop_back(); 
                }
            }
        }
        else if (c == '!') break;
    }
}