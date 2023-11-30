#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int partition(vector <pair <pair <string, string>, double> > &v, int l, int r) {
    pair <pair <string, string>, double> pivot = v[r];
    int pIndex = l;
    for(int i = l; i < r; i++) {
        if(v[i].second < pivot.second) {
            swap(v[i], v[pIndex]);
            pIndex++;
        } else if(v[i].second == pivot.second) {
            if(v[i].first.first < pivot.first.first) {
                swap(v[i], v[pIndex]);
                pIndex++;
            } else if(v[i].first.first == pivot.first.first) {
                if(v[i].first.second < pivot.first.second) {
                    swap(v[i], v[pIndex]);
                    pIndex++;
                }
            }
        }
    }
    swap(v[pIndex], v[r]);
    return pIndex;
}

void quickSort(vector <pair <pair <string, string>, double> > &v, int l, int r) {
    if(l < r) {
        int p = partition(v, l, r);
        quickSort(v, l, p - 1);
        quickSort(v, p + 1, r);
    }
}

int main() {
    int n; cin >> n;
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
    quickSort(v, 0, n - 1);
    cout << fixed << setprecision(3);
    for(int i = 0; i < n; i++) {
        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << "\n";
    }
    return 0;
}