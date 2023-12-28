#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > g;
vector <bool> used;
vector <int> states, topSortV;

bool detectCycle(int v) {
    states[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(states[to] == 0) {
            if(detectCycle(to)) {
                return true;
            }
        } else if(states[to] == 1) {
            return true;
        }
    }
    states[v] = 2;
    return false;
}

void topsort(int v) {
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) {
            topsort(to);
        }
    }
    topSortV.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;

    states.resize(n);
	g.resize(n);
	used.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    bool hasCycle = false;
    for(int i = 0; i < n; i++) {
        if(detectCycle(i)) {
            hasCycle = true;
            break;
        }
    }

    if(!hasCycle) {
        cout << "Possible" << endl;
        for(int i = 0; i < n; i++) {
            if(!used[i]) {
                topsort(i);
            }
        }
        for(int i = topSortV.size() - 1; i >= 0; i--) {
            cout << topSortV[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}