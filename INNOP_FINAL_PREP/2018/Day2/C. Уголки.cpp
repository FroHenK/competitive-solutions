#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 1000001;

int mat[1001][1001];
int mmin[1001][1001];
int mmax[1001][1001];

int sumat[1001][1001];

int mminp[1001][1001];//parent 1 is upper, 2 means lefter
int mmaxp[1001][1001];

int mminpt[1001][1001];//parent type 1 is mini 2 is maxi
int mmaxpt[1001][1001];

int mminir[1001][1001];//is reversed here to get that
int mmaxir[1001][1001];


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif


    int h, w;
    cin >> h >> w;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            cin >> mat[x][y];
            sumat[x][y] = mat[x][y];
            if (x)
                sumat[x][y] += sumat[x - 1][y];
            if (y)
                sumat[x][y] += sumat[x][y - 1];
            if (y && x)
                sumat[x][y] -= sumat[x - 1][y - 1];


        }
    }

    if (mat[0][0] > 0) {
        mmin[0][0] = -mat[0][0];
        mmax[0][0] = mat[0][0];
        mminp[0][0] = 0;
        mmaxp[0][0] = 0;
        mminir[0][0] = 1;
        mmaxir[0][0] = 0;
        mminpt[0][0] = 0;
        mmaxpt[0][0] = 0;
    } else {
        mmin[0][0] = mat[0][0];
        mmax[0][0] = -mat[0][0];
        mminp[0][0] = 0;
        mmaxp[0][0] = 0;
        mminir[0][0] = 0;
        mmaxir[0][0] = 1;
        mminpt[0][0] = 0;
        mmaxpt[0][0] = 0;
    }


    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (x == 0 && y == 0)
                continue;
            int mini = INT_MAX;
            int maxi = INT_MIN;
            int minp = -1;
            int maxp = -1;

            int minir = -1;
            int maxir = -1;

            int minpt = -1;
            int maxpt = -1;

            if (x) {
                int additional = sumat[x][y] - sumat[x - 1][y];
                if (-additional - mmin[x - 1][y] < mini) {
                    minir = 1;
                    minp = 2;
                    mini = -additional - mmin[x - 1][y];
                    minpt = 1;
                }
                if (-additional - mmin[x - 1][y] > maxi) {
                    maxir = 1;
                    maxp = 2;
                    maxi = -additional - mmin[x - 1][y];
                    maxpt = 1;
                }

                if (-additional - mmax[x - 1][y] < mini) {
                    minir = 1;
                    minp = 2;
                    mini = -additional - mmax[x - 1][y];
                    minpt = 2;
                }
                if (-additional - mmax[x - 1][y] > maxi) {
                    maxir = 1;
                    maxp = 2;
                    maxi = -additional - mmax[x - 1][y];
                    maxpt = 2;
                }


                if (additional + mmin[x - 1][y] < mini) {
                    minir = 0;
                    minp = 2;
                    mini = additional + mmin[x - 1][y];
                    minpt = 1;
                }
                if (additional + mmin[x - 1][y] > maxi) {
                    maxir = 0;
                    maxp = 2;
                    maxi = additional + mmin[x - 1][y];
                    maxpt = 1;
                }

                if (additional + mmax[x - 1][y] < mini) {
                    minir = 0;
                    minp = 2;
                    mini = additional + mmax[x - 1][y];
                    minpt = 2;
                }
                if (additional + mmax[x - 1][y] > maxi) {
                    maxir = 0;
                    maxp = 2;
                    maxi = additional + mmax[x - 1][y];
                    maxpt = 2;
                }
            }

            if (y) {
                int additional = sumat[x][y] - sumat[x][y - 1];

                if (-additional - mmin[x][y - 1] < mini) {
                    minir = 1;
                    minp = 1;
                    mini = -additional - mmin[x][y - 1];
                    minpt = 1;
                }
                if (-additional - mmin[x][y - 1] > maxi) {
                    maxir = 1;
                    maxp = 1;
                    maxi = -additional - mmin[x][y - 1];
                    maxpt = 1;
                }

                if (-additional - mmax[x][y - 1] < mini) {
                    minir = 1;
                    minp = 1;
                    mini = -additional - mmax[x][y - 1];
                    minpt = 2;
                }
                if (-additional - mmax[x][y - 1] > maxi) {
                    maxir = 1;
                    maxp = 1;
                    maxi = -additional - mmax[x][y - 1];
                    maxpt = 2;
                }


                if (additional + mmin[x][y - 1] < mini) {
                    minir = 0;
                    minp = 1;
                    mini = +additional +mmin[x][y - 1];
                    minpt = 1;
                }
                if (additional + mmin[x][y - 1] > maxi) {
                    maxir = 0;
                    maxp = 1;
                    maxi = additional + mmin[x][y - 1];
                    maxpt = 1;
                }

                if (additional + mmax[x][y - 1] < mini) {
                    minir = 0;
                    minp = 1;
                    mini = additional + mmax[x][y - 1];
                    minpt = 2;
                }
                if (additional + mmax[x][y - 1] > maxi) {
                    maxir = 0;
                    maxp = 1;
                    maxi = additional + mmax[x][y - 1];
                    maxpt = 2;
                }
            }


            mmin[x][y] = mini;
            mmax[x][y] = maxi;
            mminp[x][y] = minp;
            mmaxp[x][y] = maxp;
            mminir[x][y] = minir;
            mmaxir[x][y] = maxir;
            mminpt[x][y] = minpt;
            mmaxpt[x][y] = maxpt;
        }
    }

    int ct = 2;
    int x = w - 1;
    int y = h - 1;
    vector<pair<int, int> > resa;
    while (x || y) {
        if (ct == 1) {//we are on min
            if (mminir[x][y])
                resa.push_back({x, y});
            ct = mminpt[x][y];

            if (mminp[x][y] == 1)
                y--;
            else
                x--;
        } else {//we are on max
            if (mmaxir[x][y])
                resa.push_back({x, y});
            ct = mmaxpt[x][y];

            if (mmaxp[x][y] == 1)
                y--;
            else
                x--;
        }
    }
    if (ct == 1) {//we are on min
        if (mminir[x][y])
            resa.push_back({x, y});
    } else {//we are on max
        if (mmaxir[x][y])
            resa.push_back({x, y});
    }
    reverse(resa.begin(), resa.end());
    cout << mmax[w - 1][h - 1] << endl;
    cout << resa.size() << endl;
    for (auto i:resa)
        cout << i.second+1 << ' ' << i.first+1 << endl;
    return 0;
}