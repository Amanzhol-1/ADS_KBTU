#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 31;
long long calculateHash(string str) {
    long long hashValue = 0;
    long long power = 1;
    for(int i = 0; i < str.size(); i++) {
        int charValue = str[i] - 96; 
        long long currentHash = charValue * power % MOD;
        hashValue = (hashValue + currentHash) % MOD;
        power = (power * BASE) % MOD;
    }
    return hashValue;
}

vector<long long> computePrefixHash(string str) { //каждый элемент вектора представляет хеш-значение префикса, заканчивающегося в данной позиции текста.
    vector<long long> hashValues(str.size());
    long long power = 1;
    for(int i = 0; i < str.size(); i++) {
        int charValue = str[i] - 96; 
        hashValues[i] = charValue * power % MOD;
        if(i) {
            hashValues[i] = (hashValues[i] + hashValues[i - 1]) % MOD;
        }
        power = (power * BASE) % MOD;
    }
    return hashValues;
}

vector<int> rabinKarpSearch(string text, string pattern) { 

    long long patternHash = calculateHash(pattern);
    vector<long long> prefixHashes = computePrefixHash(text);
    vector<int> occurrences;
    for (int i = 0; i < text.size() - pattern.size() + 1; i++) {
        long long currentSubstringHash = prefixHashes[i + pattern.size() - 1];
        if (i) {
            currentSubstringHash -= prefixHashes[i - 1];
        }
        if (currentSubstringHash < 0) { 
            currentSubstringHash += MOD;
        }
        if (i) {
            patternHash = (patternHash * BASE) % MOD;
        }
        if (currentSubstringHash == patternHash) { //Перебирает текст и проверяет, соответствует ли хеш текущей подстроки хешу шаблона.
            occurrences.push_back(i);
        }
    }
    return occurrences;
}

int main() {
    string text; 
    cin >> text;
    int queryCount; 
    bool f = true;
    cin >> queryCount;
    vector<int> isSubstringFound(text.size());
    while(queryCount--) {
        string subString; 
        cin >> subString;
        vector<int> matches = rabinKarpSearch(text, subString);
        for(int i = 0; i < matches.size(); i++) {
            fill(isSubstringFound.begin() + matches[i], isSubstringFound.begin() + matches[i] + subString.size(), 1);
        }
    }
    
    for(int i = 0; i < isSubstringFound.size(); i++) { 
        if(!isSubstringFound[i]) {
            cout << "NO" << endl;
            f = false;
        }
    }
    if(f){
        cout << "YES" << endl;
    }
    return 0;
}
