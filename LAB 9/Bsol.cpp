
#include <iostream>
#include <string>
using namespace std;

long long phash(const string& s, int start, int length, int x, int q) {
    long long  res = 0;
    for (int i = start; i < start + length; i++) {
        res = (res * x + int(s[i])) % q;
    }
    return res;
}

bool rabinKarp(const string& text, const string& pattern, int k, int x = 256, int q = 1000000007) {
    int m = pattern.length();
    int n = text.length();
    int cnt = 0;
    long long patternHash = phash(pattern, 0, m, x, q);
    long long textHash = phash(text, 0, m, x, q);

    long long p = 1; 
    for (int i = 0; i < m - 1; ++i) {
        p = (p * x) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if(cnt == k){
            return true;
        }
        if (patternHash == textHash) {
            cnt++;
        }
        textHash = ((textHash - int(text[i]) * p) * x + int(text[i + m])) % q; 
        if (textHash < 0) {
            textHash += q;
        }
    }
    return false;
}

int main() {
    string p;
    string t;
    int k;
    cin>>p>>k;
    cin>>t;
    bool fl = rabinKarp(t,p,k);
    if(fl){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}