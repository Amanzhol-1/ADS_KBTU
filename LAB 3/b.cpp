#include <iostream>

using namespace std;

#define ull unsigned long long

int main() {
    ull n, k;
    cin >> n >> k;
    ull a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ull l = 0, r = 1e15;
    while(l <= r) {
        ull mid = l + (r - l) / 2, cnt = 1, sum = 0;
        for(int i = 0; i < n; i++) {
            if(mid < sum + a[i]) {
                cnt++;
                sum = 0;
            }
            if(mid < a[i]) {
                cnt = k + 1;
            } 
            sum += a[i];
        }
        if(k < cnt) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;

    return 0;
}