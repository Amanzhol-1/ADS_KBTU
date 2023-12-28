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

vector<int> kmp(const string& text, const string& pattern) {
    vector<int> result;
    int patternLength = pattern.size();
    int textLength = text.size();

    if (patternLength > textLength) {
        return result; 
    }

    string str = pattern + ";" + text; // для нахождения совпадениии с помощью преф функц
    vector<int> pref = prefix(str);

    for (int i = patternLength + 1; i <= textLength + patternLength; ++i) {
        if (pref[i] == patternLength) {
            result.push_back(i - 2 * patternLength); // вычитаем два раза паттерн так как первый раз так как мы вставили его туда во второй раз 
            // так как сам паттерн будет наден на длинну паттерна позже по логике префикс функции
        }
    }
    return result;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> occurrences = kmp(text, pattern);
    cout << occurrences.size() << endl;
    for (int i = 0; i < occurrences.size(); ++i) {
        cout << occurrences[i] + 1 << " "; // Вывод индексов начала совпадении
    }
    cout << endl;

    return 0;
}
