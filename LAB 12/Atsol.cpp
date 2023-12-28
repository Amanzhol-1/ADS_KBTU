#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 501;
int adjacencyMatrix[MAX_SIZE][MAX_SIZE], nodeValues[MAX_SIZE];
bool isNodeUsed[MAX_SIZE];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> adjacencyMatrix[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        cin >> nodeValues[i];
    }

    vector<int> result;

    for(int currentNode = 1; currentNode <= n; currentNode++){
        isNodeUsed[nodeValues[currentNode]] = true;
        int maximumDistance = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){ 
                adjacencyMatrix[i][j] = min(adjacencyMatrix[i][j], adjacencyMatrix[i][nodeValues[currentNode]] + adjacencyMatrix[nodeValues[currentNode]][j]);
                if(isNodeUsed[i] && isNodeUsed[j]){
                    maximumDistance = max(adjacencyMatrix[i][j], maximumDistance);
                }
            }
        }
        result.push_back(maximumDistance);
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}
