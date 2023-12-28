#include <iostream>
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
int main() {
    string s; 
    cin >> s;

    vector <int> occurrences = prefix(s); 
    cout << s.size() - occurrences.back() << endl; 

    return 0;
}