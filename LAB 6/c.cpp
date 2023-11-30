#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <climits> 

using namespace std;

int main() {
    int n, min_dist = INT_MAX;
    cin >> n;
    vector<int> a(n); vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<pair<int, int>, int> arr;
    map<pair<int, int>, int>::iterator itr;
    for (int i = 0; i < n - 1; i++) {
        int dist = a[i + 1] - a[i];
        arr[make_pair(a[i], a[i + 1])] = dist;
        if (dist < min_dist) {
            min_dist = dist;
        }
    }
    for (itr = arr.begin(); itr != arr.end(); ++itr) {
        if (itr->second == min_dist) {
            ans.push_back(itr->first.first);
            ans.push_back(itr->first.second);
        }
    }
    for (size_t i = 0; i < ans.size(); i++) { 
        cout << ans[i] << " ";
    }
    return 0;
}

 