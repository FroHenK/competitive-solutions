#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;
const __int64 N = 100001;

__int64 ar[N];
__int64 sum1[N];
__int64 sum2[N];
vector<int> vc1, vc2;

int n, k;

__int64 f1(__int64 v) {
    __int64 suma = 0;
    auto separ = lower_bound(vc1.begin(), vc1.end(), v) - vc1.begin();
    suma += v * separ - sum1[separ];
    suma += -v * (vc1.size() - separ) + (sum1[vc1.size()] - sum1[separ]);
    return suma;
}

__int64 f2(__int64 v) {
    __int64 suma = 0;
    auto separ = lower_bound(vc2.begin(), vc2.end(), v) - vc2.begin();
    suma += v * separ - sum2[separ];
    suma += -v * (vc2.size() - separ) + (sum2[vc2.size()] - sum2[separ]);
    return suma;
}


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ar[i] = t;
        if (i % 2)
            vc2.push_back(t);
        else
            vc1.push_back(t);
    }

    sort(vc1.begin(), vc1.end());
    sort(vc2.begin(), vc2.end());
    __int64 suma = 0;
    for (int i = 0; i < vc1.size(); ++i) {
        sum1[i] = suma;
        suma += vc1[i];
    }
    sum1[vc1.size()] = suma;

    suma = 0;
    for (int i = 0; i < vc2.size(); ++i) {
        sum2[i] = suma;
        suma += vc2[i];
    }
    sum2[vc2.size()] = suma;

    __int64 mini = LONG_LONG_MAX;

    double l = -1000000000;
    double r = 1000000000;
    while (r - l >= 0.00001) {
        double m1 = (r - l) / 3 + l;
        double m2 = -(r - l) / 3 + r;
        if (f1(static_cast<long long int>(m1)) + f2(static_cast<long long int>(m1) + k) >
            f1(static_cast<long long int>(m2)) + f2(static_cast<long long int>(m2) + k))
            l = m1;
        else
            r = m2;
    }
    mini=min(mini,f1(static_cast<long long int>(l)) + f2(static_cast<long long int>(l) + k));
    mini=min(mini,f1(static_cast<long long int>(r)) + f2(static_cast<long long int>(r) + k));

     l = -1000000000;
     r = 1000000000;
    while (r - l >= 0.00001) {
        double m1 = (r - l) / 3 + l;
        double m2 = -(r - l) / 3 + r;
        if (f1(static_cast<long long int>(m1)) + f2(static_cast<long long int>(m1) - k) >
            f1(static_cast<long long int>(m2)) + f2(static_cast<long long int>(m2) - k))
            l = m1;
        else
            r = m2;
    }
    mini=min(mini,f1(static_cast<long long int>(l)) + f2(static_cast<long long int>(l) - k));
    mini=min(mini,f1(static_cast<long long int>(r)) + f2(static_cast<long long int>(r) - k));


    cout << mini << endl;
    return 0;
}