#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n + 2][m + 2];
    vector <pair <int, int> > marios;
    int mushrooms = 0;
    for(int i = 0; i < n + 2; i++) { // создание карты
        for(int j = 0; j < m + 2; j++) {
            if(i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                arr[i][j] = 1000;
                continue;
            }
            cin >> arr[i][j];
            if(arr[i][j] == 2) { // вставка марио
                marios.push_back(make_pair(i, j));
            } else if(arr[i][j] == 1) { // вставка грибов
                mushrooms++;
            }
        }
    }

    queue <pair <int, int> > q;
    for(int i = 0; i < marios.size(); i++) {
        q.push(make_pair(marios[i].first, marios[i].second)); // позиции марио в queue
    }

    int time = 0;
    while(!q.empty()) { // пока марио не ушел в иной мир и не осталось позиции где марио был бы
        if(!mushrooms) { // если марио сожрал все грибы и потерял связь с миром то остановим цикл
            break;
        }
        int size = q.size();
        while(size--) { 
            int i = q.front().first; // для всех позиции марио обычный BFS по поиску хрибов
            int j = q.front().second;
            q.pop(); // обновление позиции
            if(arr[i - 1][j] == 1) { // проверка всех случаев для грибов
                arr[i - 1][j] = 2; // ставим марио туда
                q.push(make_pair(i - 1, j));  // ставим марио туда в queue а то он выйдет за 4 измерение
                mushrooms--;// уменьшаем кол во грибов 
            }
            if(arr[i + 1][j] == 1) {
                arr[i + 1][j] = 2;
                q.push(make_pair(i + 1, j));
                mushrooms--;
            }
            if(arr[i][j - 1] == 1) {
                arr[i][j - 1] = 2;
                q.push(make_pair(i, j - 1));
                mushrooms--;
            }
            if(arr[i][j + 1] == 1) {
                arr[i][j + 1] = 2;
                q.push(make_pair(i, j + 1));
                mushrooms--;
            }
        }
        time++; 
    }

    if(!mushrooms) {
        cout << time << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}