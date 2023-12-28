#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
bool comp(pair<pair<string, string>, double> p1, pair<pair<string, string>, double> p2){
    if(p1.second == p2.second) {
        if(p1.first.first == p2.first.first) {
            return p1.first.second >= p2.first.second;
        }
        return p1.first.first > p2.first.first;
    }
    return p1.second > p2.second;
}
void merge(vector <pair <pair <string, string>, double> > &v, int left, int mid, int right){
    int size1 = mid - left + 1;
    int size2 = right - mid;
    vector <pair <pair <string, string>, double> > v1, v2;
    for(int i = 0; i < size1; i++){
        v1.push_back(v[left + i]);
    }
    for(int i = 0; i < size2; i++){
        v2.push_back(v[mid + 1 + i]);
    }
    int l = 0, r = 0, cnt = left;
    while(l < size1 && r < size2){
        if(comp(v1[l], v2[r])){
            v[cnt] = v2[r];
            r++;
        } else {
            v[cnt] = v1[l];
            l++;
        }
        cnt++;
    }
    while(l < size1){
        v[cnt] = v1[l];
        l++;
        cnt++;
    }
    while(r < size2){
        v[cnt] = v2[r];
        r++;
        cnt++;
    }
}
void mergeSort(vector <pair <pair <string, string>, double> > &v, int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n;
    cin >> n;
    map <string, double> m;
    m["A+"] = 4.00;
    m["A"] = 3.75;
    m["B+"] = 3.50;
    m["B"] = 3.00;
    m["C+"] = 2.50;
    m["C"] = 2.00;
    m["D+"] = 1.50;
    m["D"] = 1.00;
    m["F"] = 0;
    vector <pair <pair <string, string>, double> > v;
    for(int i = 0; i < n; i++) {
        string fname, lname;
        int t, total = 0;
        cin >> fname >> lname >> t;
        double sum = 0;
        while(t--) {
            string mark;
            int credits;
            cin >> mark >> credits;
            sum += credits * m[mark];
            total += credits;
        }
        v.push_back(make_pair(make_pair(fname, lname), sum / total));
    }
    mergeSort(v, 0, n-1);
    cout << fixed << setprecision(3);
    for(int i = 0; i < n; i++){
        cout << v[i].first.first << ' ' << v[i].first.second << ' ' << v[i].second << endl;
    }
    return 0;
}