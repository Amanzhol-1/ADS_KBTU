#include <iostream>
#include <string>
using namespace std;

int cn(string t, string p) { 
    int n = t.size();
    int m = p.size();
    int i = 0;
    bool found = false;
    while(i < m) {
        int j = i;
        int l = 0;
        int cnt = 1;
        while (l < n && p[j] == t[l]) {
            if (l == n - 1) {
                found = true;
                break;
            }
            j = (j + 1) % m; // если 0 значит в конце патерна и так как по модклю m то оно не больше m и будет указывать индекс в ней который увеличивается на 1
            if (j == 0) {
                cnt++;
            }
            l++;
        }
        if (found) {
            return cnt; // сколько раз паттерн повторился
        }
        i++;
    }
    return -1;
}

int main() {
    string p;
    string t;
    cin >> p; 
    cin >> t;
    cout << cn(t, p) << endl; 
    return 0;
}