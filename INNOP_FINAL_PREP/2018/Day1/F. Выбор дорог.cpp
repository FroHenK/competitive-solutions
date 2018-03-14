#include <bits/stdc++.h>

#define __int64 long long

using namespace std;
int n, w;

set<pair<int, pair<int, int> > > st;

int pr[300];

int getP(int v) {
    return pr[v] == v ? v : pr[v] = getP(pr[v]);
}

int unite(int a, int b) {
    a = getP(a);
    b = getP(b);
    if (rand() % 2) {
        pr[a] = b;
    } else {
        pr[b] = a;
    }
}

int solve() {
    memset(pr, 0, sizeof pr);
    int suma = 0;
    for (int i = 0; i < n; ++i) {
        pr[i] = i;
    }

    for (auto i:st) {
        if (getP(i.second.first) == getP(i.second.second))
            continue;
        unite(i.second.first, i.second.second);
        suma += i.first;
    }

    int keka = getP(0);
    for (int i = 1; i < n; ++i) {
        if (keka != getP(i))
            return -1;
    }
    return suma;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    freopen("maintain.in", "r", stdin);
    freopen("maintain.out", "w", stdout);
#endif

    cin >> n >> w;
    for (int i = 0; i < w; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        st.insert({c, {a, b}});
        cout << solve() << endl;
    }

    return 0;
}