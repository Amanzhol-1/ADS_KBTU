#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int partition(vector<vector<int>>& arr, int l, int r, int columnIndex) {
    int pivot = arr[r][columnIndex];
    int pIndex = l;
    for (int j = l; j < r; j++) {
        if (arr[j][columnIndex] >= pivot) {
            swap(arr[j][columnIndex], arr[pIndex][columnIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex][columnIndex], arr[r][columnIndex]);
    return pIndex;
}

void quickSort(vector<vector<int>>& arr, int l, int r, int columnIndex) {
    if (l < r) {
        int p = partition(arr, l, r, columnIndex);
        quickSort(arr, l, p - 1, columnIndex);
        quickSort(arr, p + 1, r, columnIndex);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        quickSort(arr, 0, n - 1, i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
