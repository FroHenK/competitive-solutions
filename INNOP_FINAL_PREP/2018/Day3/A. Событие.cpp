#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 100001;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    __int64 ct = 0;
    for (int i = 0; i < m; ++i) {
        __int64 a, b;
        cin >> a >> b;
        __int64 firstIsPassing = max(ct, a - 1);
        ct = firstIsPassing + b;

    }
    cout<<ct<<endl;
    return 0;
}