#include <iostream>
#include <algorithm>

using namespace std;

int partition(char arr[], int l, int r) {
    char pivot = arr[r];
    int pIndex = l;
    for(int i = l; i < r; i++) {
        if(arr[i] > pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quickSort(char arr[], int l, int r) {
    if(l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main() {
    int n; cin >> n;
    char a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char c; cin >> c;
    
    quickSort(a, 0, n - 1);

    for(int i = n - 1; i >= 0; i--) {
        if(a[i] > c) {
            cout << a[i] << "\n";
            return 0;
        }
    }
    cout << a[n - 1] << "\n";

    return 0;
}