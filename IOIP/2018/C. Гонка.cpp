#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;
const __int64 N = 1001;

int ar[N];
__int64 popul[N];

vector<int> gotScores[N];
vector<__int64> prefixes[N];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> vck;
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        vck.push_back(t);
    }
    for (int i = k; i < n; ++i)
        vck.push_back(0);
    for (int j = 0; j < n; ++j) {
        cin >> popul[j];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            --t;
            gotScores[t].push_back(vck[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(gotScores[i].begin(), gotScores[i].end());
        __int64 suma = 0;
        prefixes[i].push_back(suma);
        for (auto j:gotScores[i]) {
            suma += j;
            prefixes[i].push_back(suma);
        }
    }


    int kekas;
    cin >> kekas;
    __int64 minkek = vck[vck.size() - 1];
    __int64 maxkek = vck[0];
    while (kekas--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        int l = 0;
        int r = 1000000000;

        while (l < r) {
            int mid = (l + r) / 2;
            __int64 sa = 0;
            __int64 sbig = 0;

            if (mid >= s) {
                sa = popul[a] + (prefixes[a][prefixes[a].size()-1]) + (mid - s) * minkek;
                sbig = popul[b] + (prefixes[b][prefixes[b].size()-1] - prefixes[b][s]) + (mid) * maxkek;
            } else {
                int mns = s - mid;
                sa = popul[a] + (prefixes[a][prefixes[a].size()-1] - prefixes[b][mns]);
                sbig = popul[b] + (prefixes[b][prefixes[b].size()-1] - prefixes[b][s]) + (mid) * maxkek;
            }


            if (sbig > sa)
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;

    }

    return 0;
}