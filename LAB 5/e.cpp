#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& arr, int i) {
    int min = i; int n = arr.size();
    int left = 2 * i + 1; int right = 2 * i + 2;
    if (left < n && arr[left] < arr[min]) {
        min = left;
    }
    if (right < n && arr[right] < arr[min]) {
        min = right;
    }
    if (min != i) {
        swap(arr[i], arr[min]);
        heapify(arr, min);
    }
}

int putMin(vector<int>& heap, long long& sum, int k) {
    if (heap.size() == 0) {
        return 0;
    }
    if (heap.size() == 1) {
        int root = heap[0];
        heap.pop_back();
        return root;
    }
    int root = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify(heap, 0);
    return root;
}

void insert(vector<int>& heap, long long& sum, int k, int value) {
    heap.push_back(value);
    sum += value;
    int i = heap.size() - 1;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
    if (heap.size() > k) {
        sum -= putMin(heap, sum, k);
    }
}

int main() {
    int q, k;
    cin >> q >> k;
    vector<int> cookies_heap;
    long long sum = 0;

    while (q--) {
        string s;
        cin >> s;
        if (s == "print") {
            if (cookies_heap.size() == 0) {
                cout << 0 << endl;
            } else {
                cout << sum << endl;
            }
        } else if (s == "insert") {
            int x;
            cin >> x;
            insert(cookies_heap, sum, k, x);
        }
    }
}
