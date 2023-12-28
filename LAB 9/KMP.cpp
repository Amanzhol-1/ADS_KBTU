#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix(string p){
    int m = p.size();
    vector<int> pref(m);
    int j = 0;
    int i = 1;
    while(i < m){
        while(j > 0 && p[i] != p[j]){
            j = pref[j - 1];
        }
        if(p[i] == p[j]){
            j++;
        }
        pref[i] = j;
        i++;
    } 
    return pref;
}

vector<int> kmp(string t, string p){
    int m = p.size();
    int n = t.size();
    int i = 0;
    int j = 0;
    vector<int> result;
    vector<int> pref = prefix(p);
    while(i < n){
        if(t[i]==p[j]){
            i++;
            j++;
        }
        if(j == m){
            result.push_back(i - j);
            j = pref[j - 1];
        }
        else if(t[i] != p[j]){
            if(j > 0){
                j = pref[j - 1];
            }
            else{
                i++;
            }
            
        }
    }
    return result;
}

int main() {
    // Пример использования
    string text = "ababcababcabcabc";
    string pattern = "abc";

    // Поиск вхождений подстроки в строку
    vector<int> occurrences = kmp(text, pattern);

    // Вывод результатов
    if (occurrences.empty()) {
        cout << "Подстрока не найдена в строке." << endl;
    } else {
        cout << "Подстрока найдена в позициях: ";
        for (int pos : occurrences) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}