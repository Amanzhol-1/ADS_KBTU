#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> ans;
    while(n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2  >> y2;
        vector <int> coords(4);
        coords.push_back(x1);
        coords.push_back(y1);
        coords.push_back(x2);
        coords.push_back(y2);
        sort(coords.begin(), coords.end());
        ans.push_back(coords[coords.size() - 1]);
    }

    sort(ans.begin(), ans.end());
    cout << ans[k - 1];

    return 0;
}