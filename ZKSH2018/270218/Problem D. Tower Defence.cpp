#include <bits/stdc++.h>


using namespace std;
#define __int64 long long

__int64 ar[100000];
__int64 sar[100000];

int main() {

#ifdef DEBUG
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

#else
    //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
#endif

    int n, m;

    cin >> n >> m;
    __int64 td = 0;
    while (m--) {
        __int64 l, r, d;
        cin >> l >> r >> d;
        td += d * (r - l + 1);
        sar[l - 1] += d;
        sar[r] -= d;
    }
    __int64 kek = 0;
    for (int i = 0; i < n; ++i) {
        kek += sar[i];

        ar[i] = td;
        td -= kek;
    }
    cin >> m;
    __int64 suma = 0;
    while (m--) {
        __int64 h, x;
        cin >> h >> x;
         --x;
        if (ar[x] < h)
            suma++;
    }
    cout << suma << endl;

    return 0;
}