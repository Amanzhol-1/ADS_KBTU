#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 1e9;
const int MAX_NODES = 200001;

vector<pair<int, int>> graph[MAX_NODES];
vector<int> distances(MAX_NODES, INF);

int shortestPath(int start, int end) {
    distances.clear();
    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = INF;
    }
    distances[start] = 0;
    set<pair<int, int>> pq;
    pq.insert(make_pair(distances[start], start));
    while (!pq.empty()) {
        int current = pq.begin()->second;
        pq.erase(pq.begin());
        for (int j = 0; j < graph[current].size(); j++) {
            int to = graph[current][j].first, len = graph[current][j].second;
            if (distances[current] + len < distances[to]) {
                pq.erase(make_pair(distances[to], to));
                distances[to] = distances[current] + len;
                pq.insert(make_pair(distances[to], to));
            }
        }
    }
    return distances[end];
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int a, b, c, q, w, e, r;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin >> q >> w >> e >> r;
    a = shortestPath(q, w) + shortestPath(w, e) + shortestPath(e, r);
    b = shortestPath(q, e) + shortestPath(e, w) + shortestPath(w, r);
    if (min(a, b) <= INF)
        cout << min(a, b);
    else
        cout << -1;
    return 0;
}
