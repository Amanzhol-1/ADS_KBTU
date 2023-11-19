#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector <int>& arr, int target) {
    int l = 1, r = arr.size();
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), p(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            p[i] = a[i];
        } else {
            p[i] = p[i - 1] + a[i];
        }
    }

    while(m--) {
        int x;
        cin >> x;
        cout << binarySearch(p, x) << "\n";
    }

    return 0;
}