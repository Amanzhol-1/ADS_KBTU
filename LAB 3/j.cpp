#include <iostream>
#include <vector>

using namespace std;

bool steal(vector <int> &arr, int h, int mid) {
    int totalH = 0;
    for(int i = 0; i < arr.size(); i++) {
        totalH += (arr[i] + mid - 1) / mid;
    }
    if(totalH > h) {
        return false;
    } 
    return true;
}

int main() {
    int n, h;
    cin >> n >> h;
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
        if(steal(v, h, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << '\n';

    return 0;
}