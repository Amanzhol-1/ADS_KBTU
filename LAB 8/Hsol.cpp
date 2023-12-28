
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string lcs(vector<string> s, int N) {
    string lcs = "";
    int minl = s[0].length();
    for (string str : s) {
        int ss = str.length();
        minl = min(minl, ss);
    }
    for (int len = 1; len <= minl; len++) {
        for (int start = 0; start <= minl - len; start++) {
            string cs = s[0].substr(start, len);
            bool fl = true; 
            for (int i = 1; i < N; i++) {
                if (s[i].find(cs) == string::npos) { //не найдена
                    fl = false;
                    break;
                }
            }
            if (fl && len > lcs.length()) {
                lcs = cs ;
            }
        }
    }

    return lcs;
}

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    cout << lcs(s,N) << endl;
    return 0;
}


