#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;

int ar[100001];
int p1[100001];
int p2[100001];


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];

    int mx = ar[0];
    vector<int> q;
    for (int i = 1; i < n; ++i) {
        p1[i] = ar[i];
        p2[i] = mx;
        if (ar[i] > mx)
            q.push_back(mx);
        if (ar[i] < mx)
            q.push_back(ar[i]);

        mx = max(mx, ar[i]);
    }
    int m;
    cin >> m;
    while (m--) {
        __int64 a;
        cin >> a;
        if (a < n)
            cout << p1[a] << ' ' << p2[a] << endl;
        else
            cout << mx << ' ' << q[(a - n) % q.size()] << endl;
    }

    return 0;
}