#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLeft(vector <int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    int start = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) {
            start = mid;
            r = mid - 1;
        } else if(arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(start == -1) {
        return l;
    }
    return start;
}

int findRight(vector <int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    int end = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) {
            end = mid;
            l = mid + 1;
        } else if(arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(end == -1) {
        return r;
    } 
    return end;
}

int diff(vector <int>& arr, int l, int r) {
    return findRight(arr, r) - findLeft(arr, l) + 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 <= l2) {
            if(r1 < l2) {
                cout << diff(v, l1, r2) - diff(v, r1 + 1, l2 - 1) << "\n";
            } else {
                cout << diff(v, l1, max(r1, r2)) << "\n";
            }
        } else {
            if(r2 < l1) {
                cout << diff(v, l2, r1) - diff(v, r2 + 1, l1 - 1) << "\n";
            } else {
                cout << diff(v, l2, max(r1, r2)) << "\n";
            }
        }
    }

    return 0;
}