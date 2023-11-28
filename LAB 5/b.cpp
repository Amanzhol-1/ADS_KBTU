#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int i) {
    int n = arr.size(); int largest = i;
    int left = 2 * i + 1; int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest);
    }
}

int main() {
    int N; cin >> N;
    vector<int> stones(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(stones, i);
    }

    while (stones.size() > 1) {
        int x = stones[0];
        stones[0] = stones.back();
        stones.pop_back();
        heapify(stones, 0);
        int y = stones[0];
        stones[0] = stones.back();
        stones.pop_back();
        heapify(stones, 0);
        int smash_result = abs(x - y);
        if (smash_result > 0) {
            stones.push_back(smash_result);
            for (int i = N / 2 - 1; i >= 0; i--) {
                heapify(stones, i);
            }
        }
    }

    if (!stones.empty()) {
        cout << stones[0] << endl;
    } else {
        cout << "0" << endl;
    }
}
