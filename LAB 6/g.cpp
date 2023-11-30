#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void swap(pair<string, string> &p1, pair<string, string> &p2) {
    pair<string, string> temp = p1;
    p1 = p2;
    p2 = temp;
}

int partition(vector<pair<string, string> >& v, int l, int r) {
    string pivot = v[r].first;
    int pIndex = l;
    for(int i = l; i < r; i++) {
        if(v[i].first <= pivot) {
            swap(v[i], v[pIndex]);
            pIndex++;
        }
    }
    swap(v[pIndex], v[r]);
    return pIndex;
}

void quickSort(vector<pair<string, string> > &v, int l, int r) {
    if(l < r){
        int p = partition(v, l, r);
        quickSort(v, l, p - 1);
        quickSort(v, p + 1, r);
    }
}

int main(){
    int n; cin >> n;
    vector <pair <string, string> > v;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int cnt = 0;
        for(int j = 0; j < v.size(); j++){
            if(v[j].second == s1){
                v[j].second = s2;
                cnt = 1;
                break;
            }
        }
        if(cnt == 0){
            v.push_back(make_pair(s1, s2));
        }
    }
    quickSort(v, 0, v.size() - 1);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}