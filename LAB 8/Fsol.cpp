#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<long long> prefhs(string s, vector <long long> pw) { 
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
    string s; 
    cin >> s;
    unordered_set <long long> uniqh;
    vector <long long> pw(s.size()); 
    long long curh ;
    pw[0] = 1;
    for (int i = 1; i < pw.size(); i++) { // степени для рабина
        pw[i] = (pw[i-1] * 31);
    }
    vector <long long> prefh = prefhs(s, pw);
    for(int i = 0; i < s.size(); i++) { // рабин   i начало под строки
        for(int j = i; j < s.size(); j++) {  // конечная позиция под строки 
            curh = prefh[j]; // хэш от 0 до j
            if(i) {
                curh -= prefh[i - 1]; // вычитаем не нужный хэш оставив от i до j
            }
            curh *= pw[s.size() - i - 1]; //верный вклад в зависимости от размера (j-i+1)
            uniqh.insert(curh);
        }
    }
    cout << uniqh.size() << endl;

    return 0;
}
