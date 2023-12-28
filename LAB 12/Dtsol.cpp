#include <iostream>
using namespace std;

const int N = 2e5 + 5, INF = 2e9 + 7;
int x[N], y[N];
int parent[N];
int answer = 0;

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (rand() % 2)
        swap(a, b);
    parent[b] = a;
    return true;
}

void binarySearch(int left, int right, int n) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        for (int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= mid)
                    unite(i, j);
            }
        }

        if (find(1) == find(n)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    binarySearch(0, INF, n);
    cout << answer;
    return 0;
}
