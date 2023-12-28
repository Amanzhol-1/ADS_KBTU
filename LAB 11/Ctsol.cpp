#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
vector<int> parent;

int findParent(int vertex) {
	if (vertex == parent[vertex]) {
		return vertex;
	}
	return parent[vertex] = findParent(parent[vertex]);
}

void uniteSets(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) {
        parent[a] = b;
    }
}

int main() {
    int numVertices, numEdges; 
    cin >> numVertices >> numEdges;
    int costX, costY; 
    cin >> costX >> costY;
    parent.resize(numVertices);
    int commonCost = min(costX, costY);
    
    while(numEdges--) {
        string type; 
        cin >> type;
        int nodeA, nodeB, weight; 
        cin >> nodeA >> nodeB >> weight;
        nodeA--; nodeB--;
        
        if(type == "both") {
            weight *= commonCost;
        } else if(type == "big") {
            weight *= costX;
        } else {
            weight *= costY;
        }
        edges.push_back(make_pair(weight, make_pair(nodeA, nodeB)));
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    for(int i = 0; i < edges.size(); i++) {
        int vertexA = edges[i].second.first;
        int vertexB = edges[i].second.second;
        int edgeCost = edges[i].first;
        if(findParent(vertexA) != findParent(vertexB)) {
            totalCost += edgeCost;
            uniteSets(vertexA, vertexB);
        }
    }
    cout << totalCost << endl;

    return 0;
}
