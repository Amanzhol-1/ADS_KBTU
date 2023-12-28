#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int> > merge(vector <vector <int> > left, vector <vector <int> > right) {
    int l = 0, r = 0;
    vector <vector <int> > result;
    while(l < left.size() && r < right.size()) {
        int left_sum = left[l][left[l].size() - 1];
        int right_sum = right[r][right[r].size() - 1];
        if(left_sum < right_sum) {
            result.push_back(right[r]);
            r++;
        } else if (left_sum > right_sum) {
            result.push_back(left[l]);
            l++;
        }  else {
            int cnt = 0;
            for(int i = 0; i < left[l].size() - 1; i++) {
                if(left[l][i] < right[r][i]) {
                    result.push_back(left[l]);
                    l++;
                    break;
                } else if (left[l][i] > right[r][i]) {
                    result.push_back(right[r]);
                    r++;
                    break;
                }
                cnt++;
            }
            if(cnt == left[l].size() - 1) {
                result.push_back(left[l]);
                l++;
            }
        }
    }
    while(l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    while(r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    return result;
}
vector <vector <int> > mergeSort(vector <vector <int> > a, int l, int r) {
    if(l == r) {
        vector <vector <int> > result;
        result.push_back(a[l]);
        return result;
    }
    int m = l + (r - l) / 2;
    vector <vector <int> > left = mergeSort(a, l, m);
    vector <vector <int> > right = mergeSort(a, m + 1, r);
    return merge(left, right);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a;
    for(int i = 0; i < n; i++) {
        vector <int> tmp;
        int total = 0;
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            tmp.push_back(x);
            total += x;
        }
        tmp.push_back(total);
        a.push_back(tmp);
    }
    vector <vector <int> > result = mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}