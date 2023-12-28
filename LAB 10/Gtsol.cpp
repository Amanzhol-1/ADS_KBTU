#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > g(501);
vector <int> states(501);

bool detectCycle(int v, pair <int, int> edge) { // DFS
    states[v] = 1; // вершина v помечаем 
    for(int i = 0; i < g[v].size(); i++) { 
        int to = g[v][i]; //проход по всем соседям v
        if(v == edge.first && to == edge.second) { // для того чтобы избежать проходя по той же стороне
            continue;
        }
        if(states[to] == 0) {  // Если вершина to еще не была посещена
            if(detectCycle(to, edge)) { // если цик обнаружен в рекурсивном вызове возвращаем нахожд цикла
                return true;
            }
        } else if(states[to] == 1) { // нашли цикл тк она перешла в начало 
            return true;
        }
    }
    states[v] = 2; // обошли V его соседей не нашли цикл многоножки
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            bool hasCycle = false;
            for(int k = 0; k < n; k++) {
                if(detectCycle(k, make_pair(i, g[i][j]))) { // проверяем все вершины(v = k) 
                    hasCycle = true;
                    break;
                }
            }
            if(!hasCycle) {
                cout << "YES" << endl;
                return 0;
            }
            states.assign(n, 0);
        }
    }
    cout << "NO" << endl;

    return 0;
}