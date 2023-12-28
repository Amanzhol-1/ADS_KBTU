#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> merge(vector<string> left, vector<string> right) {
    vector<string> result;
    int l = 0, r = 0;

    while (l < left.size() && r < right.size()) {
        if (left[l].size() < right[r].size()) {
            result.push_back(left[l]);
            l++;
        } else {
            result.push_back(right[r]);
            r++;
        }
    }
    
    while (l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    while (r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    
    return result;
}

vector<string> mergeSort(vector<string>& v) {
    if (v.size() <= 1) {
        return v;
    }

    int mid = v.size() / 2;
    vector<string> left(v.begin(), v.begin() + mid);
    vector<string> right(v.begin() + mid, v.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    vector<vector<string>> v;
    string s;

    for (int i = 0; i < t; i++) {
        getline(cin, s);
        vector<string> v1;
        string str = "";

        for (char c : s) {
            if (c == ' ') {
                if (!str.empty()) {
                    v1.push_back(str);
                }
                str = "";
            } else {
                str += c;
            }
        }

        v1 = mergeSort(v1);
        v.push_back(v1);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j < v[i].size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
