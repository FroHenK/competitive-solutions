#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

int ar[150001];
int p[150001];
int pusa[150001];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    freopen("farmer.in", "r", stdin);
    freopen("farmer.out", "w", stdout);
#endif
    int q, m, k;
    cin >> q >> m >> k;
    vector<int> as;
    vector<int> bs;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        as.push_back(t);
    }
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        bs.push_back(t);
    }
    vector<int> ps;


    for (int i = 0; i < m; ++i) {
        int cur = as[i];
        for (int j = 150000; j >= 0; --j) {
            if (j < cur)
                continue;
            if (ar[j] < cur) {
                ar[j] = cur;
                p[j] = 0;
                pusa[j] = cur;
            }
            if (ar[j - cur] + cur > ar[j]) {
                ar[j] = ar[j - cur] + cur;
                p[j] = j - cur;
                pusa[j] = cur;
            }
        }

    }
    int maxi = 0;
    int maxp = 0;
    int maxpusa = 0;

    for (int j = 0; j <= q; ++j) {
        if (maxi < ar[j]) {
            maxi = ar[j];
            maxp = p[j];
            maxpusa = pusa[j];
        }
        pusa[j]=maxpusa;
        ar[j]=maxi;
        p[j]=maxp;

    }

    map<int, int> used;
    int cur = q;
    while (cur) {
        used[pusa[cur]]++;
        cur = p[cur];
    }

    int suma = 0;
    vector<int> elses;
    for (int i = 0; i < m; ++i) {
        if (used[as[i]]) {
            used[as[i]]--;
            suma += as[i];
            continue;
        }
        elses.push_back(as[i]);
    }
    for (int i = 0; i < k; ++i) {
        elses.push_back(bs[i]);
    }
    if(suma!=maxi)
        return 1;
    q -= suma;
    sort(elses.begin(), elses.end());
    reverse(elses.begin(), elses.end());

    for (auto i:elses) {
        int mini = min(q, i);
        q -= mini;
        if (mini > 0)
            suma += mini - 1;
    }
    cout << suma << endl;
    return 0;
}