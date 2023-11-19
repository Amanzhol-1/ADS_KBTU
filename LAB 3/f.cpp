#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int l = 0, r = v.size() - 1, sum = 0, cnt = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(v[mid] <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        for(int i = 0; i < l; i++) {
            sum += v[i];
            cnt++;
        }
        cout << cnt << " " << sum << "\n";
    }

    return 0;
}