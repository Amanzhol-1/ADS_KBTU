#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<pair<int, int>>& arr, int i, int n) {
    int max = i;
    int left = 2 * i + 1; int right = 2 * i + 2;
    if (left < n && arr[left] > arr[max]) {
        max = left;
    }
    if (right < n && arr[right] > arr[max]) {
        max = right;
    }
    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, max, n);
    }
}

void buildHeap(vector<pair<int, int>>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> rows; 
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        rows.push_back({a, i});
    }
    buildHeap(rows);
    long long earnings = 0;

    while (x > 0) {
        int seats = rows[0].first;
        int row = rows[0].second;
        if (seats > 0) {
            earnings += seats;
            seats--;
            x--;
            rows[0].first = seats;
            heapify(rows, 0, n); 
        } else {
            swap(rows[0], rows[n - 1]);
            n--;
            heapify(rows, 0, n); 
        }
    }

    cout << earnings << endl;
}
