#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 2200000;

int segt[N * 4];

int sumas(int l, int r, int tl = 0, int tr = N - 1, int v = 1) {
    if (l == tl && tr == r)
        return segt[v];
    int m = (tl + tr) / 2;
    if (r <= m)
        return sumas(l, r, tl, m, v * 2);
    if (l > m)
        return sumas(l, r, m + 1, tr, v * 2 + 1);
    return sumas(l, m, tl, m, v * 2) + sumas(m + 1, r, m + 1, tr, v * 2 + 1);
}

void increments(int dest, int tl = 0, int tr = N - 1, int v = 1) {
    if (tr == tl) {
        segt[v]++;
        return;
    }
    int m = (tl + tr) / 2;
    if (dest <= m)
        increments(dest, tl, m, v * 2);
    if (dest > m)
        increments(dest, m + 1, tr, v * 2 + 1);
    segt[v] = segt[v * 2] + segt[v * 2 + 1];
}

vector<int> mat1[N];
vector<int> mat2[N];
int tmr = 0;

int l1[N];
int r1[N];

int l2[N];
int r2[N];

void dfs1(int v) {
    l1[v] = tmr++;

    for (auto i:mat1[v])
        dfs1(i);
    r1[v] = tmr++;
}

void dfs2(int v) {
    l2[v] = tmr++;

    for (auto i:mat2[v])
        dfs2(i);
    r2[v] = tmr++;
}


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    freopen("virus.in", "r", stdin);
    freopen("virus.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int b1 = -1, b2 = -1;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            b1 = i;
            continue;
        }
        t--;
        mat1[t].push_back(i);
    }


    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            b2 = i;
            continue;
        }
        t--;
        mat2[t].push_back(i);
    }
    dfs1(b1);
    tmr = 0;
    dfs2(b2);
    multiset<pair<pair<int, int>, pair<int, int> > > prs;
    for (int i = 0; i < n; ++i) {
        prs.insert({{l1[i], i},
                    {l2[i], r2[i]}});
        prs.insert({{r1[i], i},
                    {l2[i], r2[i]}});
    }
    stack<int> stk;
    stack<int> stkWas;
    __int64 suma = 0;
    for (auto i:prs) {
        if ((!stk.empty()) && stk.top() == i.first.second) {
            int was = stkWas.top();
            stk.pop();
            stkWas.pop();
            suma += sumas(i.second.first, i.second.second);
            suma -= was;
        } else {
            increments(i.second.first);
            stkWas.push(sumas(i.second.first, i.second.second));
            stk.push(i.first.second);

        }
    }
    cout << suma << endl;

    return 0;
}