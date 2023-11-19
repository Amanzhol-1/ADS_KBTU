#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> x;

    int l = 0, r = v.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(v[mid] == x) {
            cout << "Yes\n";
            return 0;
        }
        if(v[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "No\n";

    return 0;
}