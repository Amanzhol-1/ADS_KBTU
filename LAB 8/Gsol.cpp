#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <long long> hsh(string s, vector <long long> pw) {
    vector <long long> hs(s.size());
    for(int i = 0; i < s.size(); i++) {
        hs[i] = (s[i] - 'a' + 1) * pw[i];
        if(i) {
            hs[i] += hs[i - 1];
        }
    }
    return hs;
}

int main() {
    long long subhs;
    int q; 
    int strt, end;
    int cnt = 0;
    string s; 
    
    cin >> s;
    vector <long long> pw(s.size());
    pw[0] = 1;
    for(int i = 1; i < pw.size(); i++) {
        pw[i] = pw[i - 1] * 31; 
    }
    vector <long long> h = hsh(s, pw);


    cin >> q;
    while(q--) {
        subhs = 0;
        cnt = 0;
        cin >> strt >> end;
        string sub = "";
        for(int i = strt - 1; i < end; i++) {
            sub += s[i];
        }
        
        for(int i = 0; i < sub.size(); i++) {
            subhs += (sub[i] - 'a' + 1) * pw[i];
        }
        for(int i = 0; i + sub.size() - 1 < s.size(); i++) { //rabbin
            long long cur = h[i + sub.size() - 1];
            if(i) {
                cur -= h[i - 1];
            }
            if(cur == subhs * pw[i]) { // домножаем на pw[i] чтобы хэш подстроки попал на место cur
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}