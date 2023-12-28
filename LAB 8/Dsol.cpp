
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long phsh(string s, int start, int end){
    long long res = 0;
    for(int i = start; i < end + start; i++){
        res = (res * 31 + int(s[i]));
    }
    return res % 100000007;
}

int cnt(string s, string p){ // рабин карп
    int cn = 0;
    int sl = s.size();
    int pl = p.size();
    long long sh = phsh(s, 0, pl);
    long long ph = phsh(p, 0, pl);
    int pwl = 1;
    for (int i = 0; i < pl - 1; ++i) {
        pwl = (pwl * 31) % 100000007;
    }
    for(int i = 0; i <= sl - pl; i++){
        if(ph == sh){
            cn++;
        }  
        sh = ((sh - int(s[i]) * pwl) * 31 + int(s[i + pl])) % 100000007;
        if (sh < 0) {
            sh += 100000007;
        }
    }
    return cn;
}

int main(){
    int n;
    while(cin>>n && n!=0){
        string maxstr;
        vector<pair<string,int>> s(n);
        int m = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            cin>>s[i].first;
        }
        cin>>maxstr;
        for(int i=0;i<n;i++){
            c = cnt(maxstr,s[i].first);
            s[i].second = c;
            if(c >= m){
                m = c;
            }
        }
        cout<<m<<endl;
        for(int i=0;i<n;i++){
            if(s[i].second == m){
                cout<<s[i].first<<endl;
            }
        }
    }
}