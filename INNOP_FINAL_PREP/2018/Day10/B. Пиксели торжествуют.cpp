#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;

map<int, int> mp[1000000];
map<int, int> col[1000000];
map<int, map<int, int> > dakka[1000000];

set<int> mat[1000000];
vector<pair<pair<int, int>, pair<int, int> > > vc;

vector<pair<int, int> > qu;
int vis[1000000];

int colorcount[2000002];


void dfsInit(int v, int kek) {
    if (vis[v])
        return;
    vis[v] = 1;
    qu.push_back({v, kek});
    for (auto i:mat[v])
        dfsInit(i, kek);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    int it = n;
    while (it--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        --y1;
        --x1;
        vc.push_back({{x1, y1},
                      {x2, y2}});
        for (int y = y1; y < y2; ++y)
            for (int x = x1; x < x2; ++x) {
                int t;
                cin >> t;

                dakka[n - it - 1][x][y] = t;
                if (mp[x][y]) {
                    auto kek = mp[x][y] - 1;
                    mat[n - it - 1].insert(kek);
                    mat[kek].insert(n - it - 1);
                } else {
                    mp[x][y] = n - it;
                }
            }
    }


    int kek = 1;
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfsInit(i, kek++);
    }

    for (auto i:qu) {
        int id = i.first;
        int k = i.second;
        int white = k * 2;
        int black = k * 2 + 1;
        int x1 = vc[id].first.first, y1 = vc[id].first.second;
        int x2 = vc[id].second.first, y2 = vc[id].second.second;
        for (int y = y1; y < y2; ++y)
            for (int x = x1; x < x2; ++x) {
                if (col[x][y]) {
                    if ((dakka[id][x][y] ? black : white) != col[x][y]) {
                        swap(black, white);
                    }
                    break;
                }
            }


        for (int y = y1; y < y2; ++y)
            for (int x = x1; x < x2; ++x) {
                if (col[x][y]) {
                    if ((dakka[id][x][y] ? black : white) != col[x][y]) {
                        cout << -1 << endl;
                        return 0;
                    }
                    continue;
                }

                col[x][y] = (dakka[id][x][y] ? black : white);

            }
    }


    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            colorcount[col[x][y]]++;
//            cout<<col[x][y]<<' ';
        }
//        cout<<endl;
    }
    int whites = 0;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int curcol = col[x][y];
            if (!curcol) {
                whites += 1;
                continue;
            }
            int oppos = ((curcol % 2) ? curcol - 1 : curcol + 1);
            if (colorcount[oppos] < colorcount[curcol])
                whites += 1;
            if(colorcount[oppos] == colorcount[curcol])
                if(curcol%2)
                    whites+=1;

        }
    }
    cout << whites << endl;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int curcol = col[x][y];
            if (!curcol) {
                cout << 0 << ' ';
                continue;
            }
            int oppos = ((curcol % 2) ? curcol - 1 : curcol + 1);
            if (colorcount[oppos] < colorcount[curcol])
                cout << 0 << ' ';
            else if(colorcount[oppos] > colorcount[curcol])
                cout << 1 << ' ';
            if(colorcount[oppos] == colorcount[curcol])
                cout<<curcol%2<<' ';
        }
        cout << endl;
    }
    return 0;
}
