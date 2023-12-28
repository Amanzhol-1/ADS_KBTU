#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> g_road[410];
vector <int> g_air[410];
int road[405][405];

void path (vector <int> &d, vector <bool> &used, vector <int> g[]){
    queue <int> q;
    q.push(0);
    used[0] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if (!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g_road[--a].push_back(--b);
        g_road[b].push_back(a);
        road[a][b] = road[b][a] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (road[i][j] == 0 && i != j){
                g_air[i].push_back(j);
                g_air[j].push_back(i);
            }
        }
    }
    vector <int> d1(n + 1), d2(n + 1);
    vector <bool> used1(n + 1, false), used2(n + 1, false);
    path(d1, used1, g_road);
    path(d2, used2, g_air);
    if (!used1[n - 1] || !used2[n - 1]) {
        cout << -1 << endl;
    }
    else{
        cout << max(d1[n - 1], d2[n - 1]) << endl;
    } 
}