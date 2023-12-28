#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> merge(vector <int> left, vector <int> right) {
    vector <int> result;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] < right[r]) {
            result.push_back(left[l]);
            l++;
        } else {
            result.push_back(right[r]);
            r++;
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
vector <int> mergeSort(vector <int> v, int l, int r) {
    if(l == r) {
        vector <int> result;
        result.push_back(v[l]);
        return result;
    }
    int mid = l + (r - l) / 2;
    vector <int> left = mergeSort(v, l, mid);
    vector <int> right = mergeSort(v, mid + 1, r);
    return merge(left, right);
}
vector <int> mergeTwoArray(vector <int> left, vector <int> right) {
    vector <int> result;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] == right[r]) {
            result.push_back(left[l]);
            l++;
            r++;
        } else if(left[l] < right[r]) {
            l++;
        } else if(left[l] > right[r]) {
            r++;
        }
    }
    return result;
}
int main() {
    int n, m;
    cin >> n >> m;
    if(n == 0 || m == 0) {
        return 0;
    }
    vector <int> v1(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    vector <int> v2(m);
    for(int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    v1 = mergeSort(v1, 0, v1.size() - 1);
    v2 = mergeSort(v2, 0, v2.size() - 1);
    vector <int> result = mergeTwoArray(v1, v2);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}