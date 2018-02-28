#include <bits/stdc++.h>


using namespace std;
#define __int64 long long

vector<pair<int, int>> mat[10001];

int minDist[9][10001];//mindist from gold to gold


void djikstra(int from, int ind) {
    minDist[ind][from] = 0;
    set<pair<int, int> > q;
    q.insert({0, from});
    while (!q.empty()) {
        auto cur = *q.begin();
        q.erase(q.begin());
        for (auto i:mat[cur.second]) {
            if ((minDist[ind][cur.second] + i.second < minDist[ind][i.first]) || minDist[ind][i.first] == -1) {
                q.erase({minDist[ind][i.first], i.first});
                minDist[ind][i.first] = minDist[ind][cur.second] + i.second;
                q.insert({minDist[ind][i.first], i.first});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        mat[i].clear();
        for (auto &j : minDist) {
            j[i] = -1;
        }
    }
    vector<pair<int, int> > gold;
    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;
        mat[a].emplace_back(b, l);
        mat[b].emplace_back(a, l);
    }
    {
        int i;
        cin >> i;
        while (i--) {
            int t;
            cin >> t;
            gold.push_back({t, i + 1});
        }
    }

    int v;
    cin >> v;
    djikstra(0, 0);
    for (auto i : gold) {
        djikstra(i.first, i.second);
    }

    int maxi = 0;
    for (int lenkek = 1; lenkek <= gold.size(); ++lenkek) {
        sort(gold.begin(), gold.end());
        do {
            int cur = 0;
            int suma = 0;
            bool isBad = 0;
            for (int i = 0; i < lenkek; ++i) {
                suma += minDist[gold[i].second][cur];
                if (minDist[gold[i].second][cur] == -1) {
                    isBad = 1;
                    break;
                }
                cur = gold[i].first;

            }
            if (isBad)
                continue;
            suma += minDist[0][cur];
            if(suma<=v){
                maxi=lenkek;
                continue;
            }
        } while (next_permutation(gold.begin(), gold.end()));
    }

    cout<<maxi<<endl;
}


int main() {

#ifdef DEBUG
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

#else
    //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}