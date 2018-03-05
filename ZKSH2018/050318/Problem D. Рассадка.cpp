#include <bits/stdc++.h>

using namespace std;

map<int, set<int>> mp;
int sz = 0;
int isBad = 0;
map<int, int> vis;
long n, m;

void dfs(int v, int p) {
    if (vis[v]) {
        if (sz != n)
            isBad = true;
        return;
    }
    sz++;
    vis[v] = 1;
    for (auto i:mp[v]) {
        if (i == p)
            continue;
        dfs(i, v);
    }
}


void solve() {
    mp.clear();
    isBad = 0;
    vis.clear();
    set<int> ca;
    while (m--) {
        int a, b;
        cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
        ca.insert(a);
        ca.insert(b);
    }
    size_t mx = 0;
    for (auto i:mp) {
        mx = max(i.second.size(), mx);
    }
    if (mx > 2) {
        cout << "NO" << endl;
        return;
    }
    for (auto i:ca) {
        sz = 0;
        if (!vis[i])
            dfs(i, -1);
    }
    if(isBad)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif

    cin >> n >> m;

    while (n) {

        solve();
        cin >> n >> m;
    }
    return 0;
}