#pragma comment(linker, "stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>


using namespace std;
#define __int64 __int64_t

int n, m;
int ar[100004];
int vis[100004];
vector<vector<int> > groups;
vector<int> group;
vector<pair<int, int> > prs;
//vector<pair<int, int> > actions;

int iah = 1;//Is Alice home?

void dfs(int v) {
    if (vis[v])
        return;
    vis[v] = 1;
    if (ar[v] == v)
        return;
    group.push_back(v);
    dfs(ar[v]);
}

void swp(int a, int b) {
    swap(ar[a], ar[b]);
    cout << a << ' ' << b << ' ';
}

void solve() {
    memset(vis, 0, sizeof vis);
    groups.clear();
    prs.clear();

    for (int i = 0; i < n + 2; ++i) {
        ar[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        swap(ar[a], ar[b]);
    }

    for (int i = 0; i < n; ++i) {
        if ((ar[i] != i) && !vis[i]) {
            group.clear();
            dfs(i);
            if (group.size() > 2)
                groups.push_back(group);
            else {
                pair<int, int> pr;
                pr.first = i;
                pr.second = ar[i];
                prs.push_back(pr);
            }
            if (group.size() == 1)
                exit(0);
        }
    }

    for (auto pr:prs) {
        swp(pr.first, n);
        swp(pr.second, n + 1);
        swp(pr.second, n);
        swp(pr.first, n + 1);
        iah = !iah;
    }
    for (auto gr:groups) {
        swp(gr[0], n);
        for (int i = 2; i < gr.size(); ++i) {
            swp(ar[n], n);
        }
        swp(ar[n], n + 1);
        swp(gr[0], n + 1);
        swp(ar[n], n);
        iah = !iah;
    }
    if (ar[n] == n + 1)
        swp(n, n + 1);
    cout << endl;
}

int main() {

#ifdef DEBUG
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

#else
    //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
#endif

    cin >> n >> m;
    while (n) {
        solve();

        cin >> n;
        if (!n)
            return 0;
        cin >> m;
    }

    return 0;
}