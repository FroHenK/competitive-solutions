#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;

__int64 ar[300001];

set<pair<int, int>, greater<> > mat[300001];


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;


    __int64 maxi = 0;
    int maxar[4];
    int maxsz = 0;

    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        if (ar[i] > maxi) {
            maxi = ar[i];
            maxar[0] = i;
            maxsz = 1;
        }
    }

    vector<pair<int, int> > prs;
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        mat[a].insert({ar[b], b});
        mat[b].insert({ar[a], a});
        prs.emplace_back(a, b);
    }


    for (auto i:prs) {
        if (ar[i.first] + ar[i.second] > maxi) {
            maxi = ar[i.first] + ar[i.second];
            maxsz = 2;
            maxar[0] = i.first;
            maxar[1] = i.second;
        }
        int kek1 = 4;
        for (auto j1:mat[i.first]) {
            if (!kek1)
                break;
            kek1--;
            int v1 = j1.second;
            if (v1 == i.second || v1 == i.first)
                continue;
            if (ar[i.first] + ar[i.second] + ar[v1] > maxi) {
                maxi = ar[i.first] + ar[i.second] + ar[v1];
                maxsz = 3;
                maxar[0] = i.second;
                maxar[1] = i.first;
                maxar[2] = v1;
            }
        }
        int kek2 = 4;
        for (auto j2:mat[i.second]) {
            if (!kek2)
                break;
            kek2--;
            int v2 = j2.second;
            if (v2 == i.second || v2 == i.first)
                continue;
            if (ar[i.first] + ar[i.second] + ar[v2] > maxi) {
                maxi = ar[i.first] + ar[i.second] + ar[v2];
                maxsz = 3;
                maxar[0] = i.first;
                maxar[1] = i.second;
                maxar[2] = v2;
            }
        }

        kek1 = 4;
        for (auto j1:mat[i.first]) {
            if (!kek1)
                break;
            kek1--;
            int v1 = j1.second;
            if (v1 == i.second || v1 == i.first)
                continue;
            kek2 = 4;
            for (auto j2:mat[i.second]) {
                if (!kek2)
                    break;
                kek2--;
                int v2 = j2.second;
                if (v2 == i.second || v2 == i.first)
                    continue;
                if (v2 == v1)
                    continue;
                if (ar[i.first] + ar[i.second] + ar[v2] + ar[v1] > maxi) {
                    maxi = ar[i.first] + ar[i.second] + ar[v2] + ar[v1];
                    maxsz = 4;

                    maxar[0] = v1;
                    maxar[1] = i.first;
                    maxar[2] = i.second;
                    maxar[3] = v2;
                }
            }
        }

    }


    cout << maxsz << endl;
    for (int i = 0; i < maxsz; ++i)
        cout << maxar[i] + 1 << ' ';


    return 0;
}
