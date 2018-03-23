#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;
const __int64 N = 1000001;


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif


    int n;
    cin >> n;
    vector<double> v1;
    vector<double> v2;
    double suma1 = 0;
    double suma2 = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
        total += 2;
        suma1 += a;
        suma2 += b;
    }
    double maxi = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    reverse(v1.begin(), v1.end());


    while (v1.size() && v2.size()) {
        maxi = max(maxi, min(suma1, suma2) - total);
        if (suma1 > suma2) {
            suma1 -= v1.back();
            v1.pop_back();
            total -= 1;
            continue;
        }
        suma2 -= v2.back();
        v2.pop_back();
        total -= 1;
    }
    cout<<maxi<<endl;
    return 0;
}
