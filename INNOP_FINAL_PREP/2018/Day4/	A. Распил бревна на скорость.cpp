#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 1000001;
const int INF = 1000000;
vector<int> prs;

__int64 getMin(__int64 a) {
    long long int lim = static_cast<long long int>(sqrtl(a)) + 1;
    for (auto i:prs) {
        if (i >= a)
            break;
        if (a % i == 0) {
            return i;
        }
    }
    return -1;
}

int p[N];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    hash<string> h;

    __int64 n;
    cin >> n;

    p[0] = p[1] = 1;
    for (int i = 2; i <= N; ++i)
        if (!p[i]) {
            prs.push_back(i);
            if (i * 1ll * i <= N)
                for (int j = i * i; j <= N; j += i)
                    p[j] = 1;
        }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    auto a = getMin(n);
    if (a == -1) {
        cout << 1 << endl;
        return 0;
    }
    __int64 suma = 1;
    n -= a;
    a = getMin(n);
    if (a != -1)
        suma += n / a;
    else
        suma += 1;
    cout << suma << endl;


    return 0;
}