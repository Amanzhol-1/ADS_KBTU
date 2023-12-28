
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
int main() {
    int t; 
    cin >> t;
    while(t--) {
        string s; 
        cin >> s; 
        int k; 
        cin >> k; 
        vector <int> pref = prefix(s); 
        int minlen = s.size() - pref.back(); // Вычисляем длину строки, необходимую для того чтобы префикс не совпал с наиб суффиксом
        // так как нам нужно чтобы имя было без повторов коротким
        cout << minlen * (k - 1) + s.size() << endl; // Выводим результат для того чтобы подстрока входила в строку как минимум k раз, 
        //мы можем взять k−1 копий короткого имени и добавить исходную строку s к последней копии.
    }

    return 0;
}
