#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> graph[200500];
vector<int> parent;

int findParent(int vertex) {
    if (vertex == parent[vertex]) {
        return vertex;
    }
    return parent[vertex] = findParent(parent[vertex]);
}

bool uniteSets(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) {
        parent[a] = b;
        return true;
    }
    return false;
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    parent.resize(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int vertexA, vertexB;
        cin >> vertexA >> vertexB;
        vertexA--;
        vertexB--;
        graph[vertexA].push_back(vertexB);
        graph[vertexB].push_back(vertexA);
    }

    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    unordered_set<int> uniqueSet;
    vector<int> result;
    int count = 0;
    for (int i = numVertices - 1; i >= 0; i--) {
        result.push_back(count);
        count++;
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] > i && uniteSets(i, graph[i][j])) {
                count--;
            }
        }
    }

    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
