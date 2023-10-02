#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n; cin >> n; 
    string s; cin >> s;
    deque <int> dk; 
    deque <int> ds;
    int buf = 1;

    for (int i = 0; i < n; i++){
        if(s[i] == 'K'){
            dk.push_back(i + 1);
        }
        else {
            ds.push_back(i + 1);
        }
    }

    while (!dk.empty() and !ds.empty()){
        if (dk.front() != buf and ds.front() != buf){
            buf++;
        }
        if (ds.front() == buf){
            dk.pop_front();
            ds.push_back(buf);
            ds.pop_front();
        } 
        if (dk.front() == buf){
            ds.pop_front();
            dk.push_back(buf);
            dk.pop_front();
        }
         if (buf == s.size()){
            buf = 1;
        }
    }

    if (dk.empty()){
        cout << "SAKAYANAGI";
    }
    else{
        cout << "KATSURAGI";
    }

}
//KSKS 1234 K:1,3 | S: 2,4 | 

// KSKS KXKX K WON 
// SSKKK SSXKK SSXXK XSXXK 1) раунд кончился XSXXX S WON