#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > g(100001); // adjList
vector <bool> used(100001);
vector <int> components; // вершины от x

void dfs(int v) {
    used[v] = true;
    components.push_back(v); // вставка элемента
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    bool f = true;
    while(m--) {
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int x, y;
    cin >> x >> y;
    dfs(x);
    for(int i = 0; i < components.size(); i++) {
        if(y == components[i]) { // если дфс прошелся и дошел до y то он в components
            cout << "YES" << endl;
            f = false;
        }
    }
    if(f){
        cout << "NO" << endl; // не нашли путь от x до y
    }
    return 0;
}