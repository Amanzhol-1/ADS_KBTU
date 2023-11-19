#include <iostream>

using namespace std;

int binarySearchIncreasing(int arr[], int l, int r, int target) {
    if(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            return binarySearchIncreasing(arr, l, mid - 1, target);
        } else {
            return binarySearchIncreasing(arr, mid + 1, r, target);
        }
    }
    return -1;
}

int binarySearchDecreasing(int arr[], int l, int r, int target) {
    if(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            return binarySearchDecreasing(arr, mid + 1, r, target);
        } else {
            return binarySearchDecreasing(arr, l, mid - 1, target);
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    int arr[t];
    for(int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int x = 0; x < t; x++) {
        for(int i = 0; i < n; i++) {
            if(i % 2 == 1) {
                int index = binarySearchIncreasing(a[i], 0, m - 1, arr[x]);
                if(index != -1) {
                    cout << i << " " << index << "\n";
                    break;
                } else if(i + 1 == n) {
                    cout << -1 << "\n";
                    break;
                }
            } else {
                int index = binarySearchDecreasing(a[i], 0, m - 1, arr[x]);
                if(index != -1) {
                    cout << i << " " << index << "\n";
                    break;
                } else if(i + 1 == n) {
                    cout << -1 << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}