#include <iostream>
#include <vector>

using namespace std;

bool flight(vector <int> &arr, int f, int mid) {
    int total = 0;
    for(int i = 0; i < arr.size(); i++) {
        total += (arr[i] + mid - 1) / mid;
    }
    if(total > f) {
        return true;
    } 
    return false;
}

int main() {
    int n, f;
    cin >> n >> f;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int max = (int)-1e9;
    for(int i = 0; i < v.size(); i++) {
        if(max < v[i]) {
            max = v[i];
        }
    }
    
    int l = 1, r = max, res = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(flight(v, f, mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res + 1 << '\n';

    return 0;
}