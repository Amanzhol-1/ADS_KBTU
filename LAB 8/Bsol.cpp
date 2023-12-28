
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

long long phash(const string& s, int start, int length, int x, int q) {
    long long  res = 0;
    for (int i = start; i < start + length; i++) {
        res = (res * x + int(s[i])) % q;
    }
    return res;
}
//abcd
//gdabcdsfs
vector<int> rabinKarp(const string& text, const string& pattern, int x = 256, int q = 1000000007) {
    int m = pattern.length();
    int n = text.length();
    vector<int> pr;
    long long patternHash = phash(pattern, 0, m, x, q); //abcd
    long long textHash = phash(text, 0, m, x, q); //gdab

    long long p = 1; // при использовании pow для long long выдает не верное чило по этому использую такй метод возводя x в m-1
    for (int i = 0; i < m - 1; ++i) {
        p = (p * x) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            pr.push_back(i);
        }
        textHash = ((textHash - int(text[i]) * p) * x + int(text[i + m])) % q; 
        if (textHash < 0) {
            textHash += q;
        }
    }
    return pr;
}

int main() {
    string s1, s2, t;
    cin>>s1;
    cin>>s2;
    cin>>t;
    vector<int> rs1 = rabinKarp(s1, t);
    vector<int> rs2 = rabinKarp(s2, t);
    int cnt = 0;
    int i = 0;
    int j = 0;
    while(i < rs1.size() && j < rs2.size()){
        if(rs1[i] == rs2[j]){
            cnt++;
            i++;
            j++;
        }
        else if(rs1[i] < rs2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    cout << cnt;
    return 0;
}


