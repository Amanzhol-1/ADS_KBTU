#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, cost;
};

int n;
const int INF = 1e9;
bool hasCycle = false;

void bellmanFord(const vector<Edge>& edges, int start) {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    dist[start] = 0;

    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (const Edge& edge : edges) {
            if (dist[edge.from] < INF) {
                if (dist[edge.to] > dist[edge.from] + edge.cost) {
                    dist[edge.to] = max(-INF, dist[edge.from] + edge.cost);
                    parent[edge.to] = edge.from;
                    x = edge.to;
                }
            }
        }
    }

    if (x == -1) {
        hasCycle = false;
    } else {
        int y = x;
        vector<int> cyclePath;

        while (true) {
            cyclePath.push_back(y);
            y = parent[y];
            if (y == cyclePath[0] && cyclePath.size() > 1) {
                break;
            }
        }

        reverse(cyclePath.begin(), cyclePath.end());

        cout << "YES" << endl;
        cout << cyclePath.size() << endl;
        for (int i = 0; i < cyclePath.size(); ++i) {
            cout << cyclePath[i] + 1 << ' ';
        }
        cout << endl;
        hasCycle = true;
    }



}

int main() {
    cin >> n;
    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cost;
            cin >> cost;
            edges.push_back({i, j, cost});
        }
    }

    for (int i = 0; i < n; ++i) {
        bellmanFord(edges, i);
        if (hasCycle) break;
    }

    if (!hasCycle) {
        cout << "NO" << endl;
    }

    return 0;
}
