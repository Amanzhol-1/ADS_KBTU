#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, pair<int, int>>> g;
vector<int> p;

int dsu_get(int v){
    if (v == p[v]) return v;
    return p[v] = dsu_get(p[v]);
}

void dsu_unite(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);

    if (a != b){
        p[a] = b;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    long long res = 0;
    g.resize(n);
    p.resize(n);
    while(q--){
        int l, r;
        long long w;
        cin >> l >> r >> w;
        l--;
        r--;
        
        g.push_back(make_pair(w, make_pair(l, r)));
        
    }
    
    sort(g.begin(), g.end());

    for (int i = 0; i < n; i++) p[i] = i;

    for (int i = 0; i < g.size(); i++){
        int u = g[i].second.first;
        int v = g[i].second.second;
        long long w = g[i].first;
        for (int j = u + 1; j <= v; j++){
            if (dsu_get(u) != dsu_get(j)){
                res += w;
                dsu_unite(u, j);
            }
            else{
                j = p[u];
            }
            
        }
        
        
    }

    cout << res << endl;
}
