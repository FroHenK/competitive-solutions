#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;
const __int64 N = 500001;

__int64 segt[N * 4];

__int64 sumas(int l, int r, int tl = 0, int tr = N - 1, int v = 1) {
    if (l == tl && tr == r)
        return segt[v];
    int m = (tl + tr) / 2;
    if (r <= m)
        return sumas(l, r, tl, m, v * 2);
    if (l > m)
        return sumas(l, r, m + 1, tr, v * 2 + 1);
    return sumas(l, m, tl, m, v * 2) + sumas(m + 1, r, m + 1, tr, v * 2 + 1);
}

void increments(int dest, int kek, int tl = 0, int tr = N - 1, int v = 1) {
    if (tr == tl) {
        segt[v] = kek;
        return;
    }
    int m = (tl + tr) / 2;
    if (dest <= m)
        increments(dest, kek, tl, m, v * 2);
    if (dest > m)
        increments(dest, kek, m + 1, tr, v * 2 + 1);
    segt[v] = segt[v * 2] + segt[v * 2 + 1];
}


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int sz = 0;
    int m;
    cin >> m;
    while (m--) {
        int ty;
        int k;
        cin >> ty >> k;
        if (ty == 1) {
            increments(sz, k);
            sz++;
            continue;
        }
        --k;
        auto kek = sumas(k, k);
        auto kek1 = sumas(0, k);
        cout << kek1 - kek << endl;
        increments(k,0);


    }
    return 0;
}