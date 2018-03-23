#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;

__int64 car[100003];
__int64 nar[100003];


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    __int64 n, k, r;
    cin >> n >> k >> r;
    for (int i = 0; i < n; ++i) {
        car[i] = 1;
    }
    map<__int64, bool> mp;
    __int64 mini = r;

    k -= 1;
    while (k) {
        nar[0] = 1;
        int isGood = 0;
        for (int i = 1; i < n; ++i) {
            nar[i] = nar[i - 1] + car[i];
            if (nar[i] >= INF) {
                nar[i] = INF;
                break;
            }
            if (r % nar[i] == 0) {
                mini = min(mini, r / nar[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nar[i] >= INF) {
                nar[i] = INF;
                break;
            }
            car[i] = nar[i];
//            cout << nar[i] << ' ';
        }
//        cout << endl;

//        if (!isGood)
//            break;
        k--;
    }
    cout << mini << endl;

    return 0;
}