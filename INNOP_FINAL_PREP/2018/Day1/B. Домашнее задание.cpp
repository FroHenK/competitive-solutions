#include <bits/stdc++.h>

#define __int64 long long

using namespace std;
int ar[1000000];
int kak[1000000];


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    int suma = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        suma += ar[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ar[a] = 0;
    }
    cout << suma - (*max_element(ar, ar + n)) << endl;

    return 0;
}