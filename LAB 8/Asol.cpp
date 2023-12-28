#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

long long mhash(const string &s) {
    long long val = 0;
    long long p = 1;
    for (char ch: s) {
        val = (val + (ch - 47) * p) % 1000000007;
        p = (p * 11) % 1000000007;
    }
    return val;
}

int main() {
    int N; 
    cin >> N;
    vector <string> v;
    map <string, bool> map;
    for(int i = 0; i < 2 * N; i++) {
        string s; // a b c ->h 1 2 3     // 1 2 3 -h> 4 5 6  for 4 5 6 => false
        cin >> s;
        v.push_back(s);
        map[s] = true;// a b c 1 2 3 => true
    }

    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(cnt == N) {
            break;
        }
        string hash = to_string(mhash(v[i])); // if v[i] = string -> hash = inputed hash in v else if v[i] = hash then hash(hash) =hash (4 5 6) that not in v do map is false
        if(map[hash]) {  
            cout << "Hash of string " << '"' << v[i] << '"' << " is " << hash << endl;
            cnt++;
        }
    }
    
    return 0;
}