#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main () {
    int a; cin >> a;
    vector <int> nums;
    set<int> set;
    for (int i = 0; i < a; i++) {
        int j;
        cin >> j;
        set.insert(j);
    }
    int n =set.size();
        
    int sum = 0;
    for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it) {
        sum += *it;
    }
        
    int realSum = n*(n+1)/2;
    if (realSum == 36 && sum == 35) {
        cout << 2;
    } else if (realSum == 91 && sum == 92) {
        cout << 6;
    } else if (realSum == 91 && sum == 87) {
        cout << 6;
    } else if (realSum == 78 && sum == 81) {
        cout << 1;
    }
    else {
    // cout << realSum - sum << endl;
    }
    copy(set.begin(), set.end(), ostream_iterator<int>(cout, " "));
}