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
    int cnt = 0;
    vector <int> occurrences = prefix(s); 
    for(int i = 1; i < occurrences.size(); i++) { 
        if(i % 2 == 0) {
            if((i / (i - occurrences[i - 1])) % 2 == 0) { // i - occurrences[i - 1] - это длинна самого префикса и i/ это это кол во префиксов в строке до i и 
                cnt++; // если оно кратно 2 то увеличиваем счетчик
            }
        }
    } 
    cout << cnt << endl;

    return 0;
}

// ex

//hhghg  str
//01010  occ
//12345   i
//11335 delta
// 1 3  
// 2    i/delta
// 1      result

//hhghhgg   str
//0101230   occ
//1234567    i
//0133337   delta
// 211121   i/delta
// 1   2    result

//hahaghahaghj
//001201234560
//123456789123
// 2 2 5 5 5 3
// 1 2     2 1
//   1     2     