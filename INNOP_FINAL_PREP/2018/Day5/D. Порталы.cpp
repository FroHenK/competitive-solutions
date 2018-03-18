#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 500001;
const int INF = 1000000;

int mat[600][600];
int keka[600][600];
int vis[600][600];

set<int> vert[600];
set<int> hor[600];


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int h, w;
    cin >> h >> w;
    int sx = -1, sy = -1;
    int fx = -1, fy = -1;

    for (int y = 0; y < h; ++y) {

        string t;
        cin >> t;
        for (int x = 0; x < w; ++x) {
            keka[x][y] = INF;
            if (t[x] == '#') {
                hor[y].insert(x);
                vert[x].insert(y);
                mat[x][y] = 1;
            }
            if (t[x] == 'C') {
                sx = x;
                sy = y;
            }
            if (t[x] == 'F') {
                fx = x;
                fy = y;
            }


        }
    }
    set<pair<int, pair<int, int>>> q;
    q.insert({0, {sx, sy}});
    while (!q.empty()) {
        auto cur = *q.begin();
        auto curpos = cur.second;
        q.erase(q.begin());
        vis[curpos.first][curpos.second] = 1;

        set<pair<int, int> > nxt;
        if (!mat[curpos.first + 1][curpos.second])
            nxt.insert({curpos.first + 1, curpos.second});
        if (!mat[curpos.first - 1][curpos.second])
            nxt.insert({curpos.first - 1, curpos.second});
        if (!mat[curpos.first][curpos.second + 1])
            nxt.insert({curpos.first, curpos.second + 1});
        if (!mat[curpos.first][curpos.second - 1])
            nxt.insert({curpos.first, curpos.second - 1});


        for (auto i:nxt) {
            if (vis[i.first][i.second])
                continue;
            if (keka[i.first][i.second] > cur.first + 1) {
                q.erase({keka[i.first][i.second], {i.first, i.second}});
                keka[i.first][i.second] = cur.first + 1;
                q.insert({keka[i.first][i.second], {i.first, i.second}});
            }
        }


        set<pair<int, int> > walls;
        int nx, ny;
        nx = curpos.first;
        ny = (*vert[curpos.first].upper_bound(curpos.second)) - 1;
        if (!mat[nx][ny])
            walls.insert({nx, ny});
        nx = curpos.first;
        ny = (*--vert[curpos.first].upper_bound(curpos.second)) + 1;
        if (!mat[nx][ny])
            walls.insert({nx, ny});
        ny = curpos.second;
        nx = (*hor[curpos.second].upper_bound(curpos.first)) - 1;
        if (!mat[nx][ny])
            walls.insert({nx, ny});
        ny = curpos.second;
        nx = (*--hor[curpos.second].upper_bound(curpos.first)) + 1;
        if (!mat[nx][ny])
            walls.insert({nx, ny});
        int mini = INF;

        for (auto i:walls) {
            mini = min(mini, abs(i.first - curpos.first) + abs(i.second - curpos.second));
        }

        for (auto i:walls) {
            if (vis[i.first][i.second])
                continue;
            if (keka[i.first][i.second] > cur.first + 1 + mini) {
                q.erase({keka[i.first][i.second], {i.first, i.second}});
                keka[i.first][i.second] = cur.first + 1 + mini;
                q.insert({keka[i.first][i.second], {i.first, i.second}});
            }
        }

    }

    if (vis[fx][fy])
        cout << keka[fx][fy] << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}