#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int minVal = i;
    int left = 2 * i + 1; int right = 2 * i + 2;
    if (left < n && arr[left] < arr[minVal]) {
        minVal = left;
    }
    if (right < n && arr[right] < arr[minVal]) {
        minVal = right;
    }
    if (minVal != i) {
        swap(arr[i], arr[minVal]);
        heapify(arr, n, minVal);
    }
}

void buildHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> densities(n);
    for (int i = 0; i < n; i++) {
        cin >> densities[i];
    }
    buildHeap(densities);
    int operations = 0;

    while (densities[0] < m) {
        if (densities.size() < 2) {
            cout << -1 << endl;
            return 0;
        }
        int least = densities[0];
        swap(densities[0], densities[densities.size() - 1]);
        densities.pop_back();
        heapify(densities, densities.size(), 0);
        int secondLeast = densities[0];
        swap(densities[0], densities[densities.size() - 1]);
        densities.pop_back();
        heapify(densities, densities.size(), 0);
        int newDensity = least + 2 * secondLeast;
        densities.push_back(newDensity);
        heapify(densities, densities.size(), densities.size() - 1);
        operations++;
    }

    cout << operations << endl;
}
