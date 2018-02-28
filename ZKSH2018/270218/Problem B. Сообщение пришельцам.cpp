#include <bits/stdc++.h>


using namespace std;
#define __int64 long long

int n;

const int INF = 1000000;

int dp[131072][17];
int ar[131072];
int setat[131072];
int sz = 0;

void a(int v) {
    if (!setat[v])
        ar[sz++] = v;
    setat[v] = 1;
}

void solve() {
    memset(setat, 0, sizeof setat);
    memset(dp, 0, sizeof dp);
    sz = 0;
    string t1;
    string t2;
    cin >> t1 >> t2;
    int st = 0;
    int ft = 0;

    for (int i = 0; i < n; ++i) {
        if (t1[i] == 'B')
            st |= 1 << i;
        if (t2[i] == 'B')
            ft |= 1 << i;
    }
    for (int i = 0; i < n; ++i) {
        if ((1 << i) & (st ^ ft))
            dp[st ^ ft][i] = 1;
    }
    a(st ^ ft);

    for (int k = 0; k < sz; ++k) {
        int v = ar[k];
        for (int i = 0; i < n; ++i) {
            if (!(v & (1 << i)))
                continue;
            for (int j = 0; j < n; ++j) {
                if (!((v & (1 << j)) && ((st & (1 << i)) != (st & (1 << j)))))
                    continue;
                int mini = INF;
                for (int l = 0; l < n; ++l) {
                    if (dp[v][l] && dp[v][l] + abs(l - i) < mini)
                        mini = dp[v][l] + abs(l - i);
                }
                mini += abs(i-j);
                if (dp[v ^ (1 << j) ^ (1 << i)][j] > mini || !dp[v ^ (1 << j) ^ (1 << i)][j])
                    dp[v ^ (1 << j) ^ (1 << i)][j] = mini;
                a(v ^ (1 << j) ^ (1 << i));
            }
        }
    }

    int mini=INF;
    for (int i = 0; i < n; ++i) {
        if(dp[0][i] && dp[0][i]<mini)
            mini=dp[0][i];
    }
    cout<<mini-1<<endl;
}


int main() {

#ifdef DEBUG
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

#else
    //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
#endif
    cin >> n;

    while (n) {
        solve();
        cin >> n;
    }
    return 0;
}