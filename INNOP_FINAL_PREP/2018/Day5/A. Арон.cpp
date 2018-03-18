#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 1000001;
const int INF = 1000000;
__int64 mp[256];

int def1, def2;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    hash<string> h;
    int k, a, b, c, d;
    cin >> k >> a >> b >> c >> d;
    def1 = b - a + 1;
    def2 = d - c + 1;
    int monid = 0;
    int tarPos = d + 1;
    monid=k;//why kill one hp monsters?
    while (true) {
        int monHealth = monid / k + 1;
        int isAlive = 1;
        if (def1 > 1) {
            int pn = min(monHealth, def1);
            monHealth -= pn;
            def1 -= pn - 1;
        } else
            monHealth -= def1;

        if (monHealth <= 0) {
            isAlive = 0;
            monHealth = 1;
        }

        if (def2 > 1) {
            int pn = min(monHealth, def2);
            monHealth -= pn;
            def2 -= pn - 1;
        } else
            monHealth -= def2;


        if (monHealth <= 0) {
            isAlive = 0;
            monHealth = 1;
        }

        if (isAlive)
            break;
        monid++;
    }
    //cout << monid << endl;
    int monPos = -1 - monid;

    cout << tarPos-monPos << endl;
    return 0;
}