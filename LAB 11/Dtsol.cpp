#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> minEdge, parent;

int main() {
    int numVertices;
    cin >> numVertices;
    graph.resize(numVertices);
    for (int i = 0; i < numVertices; i++) {
        graph[i].resize(numVertices);
    }

    visited.resize(numVertices);
    parent.assign(numVertices, -1);
    minEdge.assign(numVertices, 1e9);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    minEdge[0] = 0;
    int totalWeight = 0;
    for (int i = 0; i < numVertices; i++) {
        int currentVertex = -1;
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && (currentVertex == -1 || minEdge[j] < minEdge[currentVertex])) {
                currentVertex = j;
            }
        }
        visited[currentVertex] = true;
        if (parent[currentVertex] != -1) {
            totalWeight += graph[currentVertex][parent[currentVertex]];
        }
        for (int j = 0; j < numVertices; j++) {
            if (graph[currentVertex][j] < minEdge[j]) {
                minEdge[j] = graph[currentVertex][j];
                parent[j] = currentVertex;
            }
        }
    }
    cout << totalWeight << endl;

    return 0;
}
