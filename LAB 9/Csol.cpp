#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix(string p){
    int m = p.size();
    vector<int> pref(m);
    int j = 0; // j - и длинна подстроки и индекс до длинны префикса
    int i = 1;
    while(i < m){
        while(j > 0 && p[i] != p[j]){
            j = pref[j - 1]; // ищем макс длинну префикаса если не совпало уменьшшаем ее пока не совпадет
        }
        if(p[i] == p[j]){
            j++; // увеличиваем размер если совпадение
        }
        pref[i] = j; // ставим этот размер на i если j 0 то i это начало этого префикса
        i++;
    } 
    return pref;
}
//ababaca
//0012301  j-1 указывает на индекс совпадения
int kmp(string t, string p){
    int m = p.size();
    int n = t.size();
    int i = 0;
    int j = 0; // индекс в p
    vector<int> occur;
    vector<int> pref = prefix(p);
    while(i < n){
        if(t[i]==p[j]){
            i++;
            j++;
        }
        if(j == m){ // p полностью входит в t 
            occur.push_back(i - j);// вставляем индекс начала этой под строки которая совпала с p
            j = pref[j - 1]; // уменьшаем размер подстроки в p для проверки
        }
        else if(t[i] != p[j]){// если символы не совпали 
            if(j > 0){
                j = pref[j - 1];
            }
            else{ // длинна префикса отрицательна следовательно мы переходим на следующий индекс 
                i++;
            }
            
        }
    }
    if(!occur.empty()){ 
        return n  - occur[0] - m; // выводим совпадения
    }
    else{
        return -1;
    }
}

int main() {
    string text = "";
    string pattern = "";
    cin>>text>>pattern;
    if(text.size()!=pattern.size()){
        cout<<-1<<endl;
    }
    else{
        text += text;
        int res = kmp(text, pattern);
        cout<<res<<endl;
    }
    return 0;
}

// dtsize - 1 - (first + plen - 1)
// zabcd
// cdzab +2
// abcdz +2  => 4

// abcabc
//   cab1

// zabcdzabcd 9 - 5 
//  abcdz1234

//cfab
//abcf
//cfabcfab
//  abcf12