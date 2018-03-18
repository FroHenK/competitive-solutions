#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 500001;
const int INF = 1000000;

int pr[26][N];
int keka[26];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    hash<string> h;
    string st;
    cin >> st;
    int l = 0;
    for (auto i:st) {

        for (int j = 0; j < 26; ++j) {
            pr[j][l] = keka[j];
        }
        keka[i - 'a']++;
        l++;
    }
    for (int j = 0; j < 26; ++j) {
        pr[j][l] = keka[j];
    }

    int n;
    cin >> n;

    while (n--) {
        memset(keka, 0, sizeof keka);
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        for (int j = 0; j < 26; ++j) {
            keka[j] -= pr[j][a];
            keka[j] += pr[j][b];
            keka[j] += pr[j][c];
            keka[j] -= pr[j][d];
        }
        int m1 = *min_element(keka, keka + 26);
        int m2 = *max_element(keka, keka + 26);

        if (m1 == m2 && m1 == 0) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;

    }
    return 0;
}