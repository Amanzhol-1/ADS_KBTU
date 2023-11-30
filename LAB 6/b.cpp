#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k = 0, j = 0;
    int n, m;
    cin >> n >> m;
    vector<int> array1(n); vector<int> array2(m);
    for (int i = 0; i < n; i++) {
        cin >> array1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> array2[i];
    }
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
    vector<int> ans;
    while (k < n && j < m) {
        if (array1[k] == array2[j]) {
            ans.push_back(array1[k]);
            k++;
            j++;
        } else if (array1[k] < array2[j]) {
            k++;
        } else {
            j++;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}