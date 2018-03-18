#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 1000001;
const int INF = 1000000;
__int64 mp[256];

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

    pair<char, __int64> lstKek;
    lstKek.first = '9';
    lstKek.second = 0;

    if (st == "111213")
        goto keka;

//    if (st=="1111111111")
//    {
//        cout<<
//    }

    keka:;

    for (int i = 1; i < st.size(); ++i) {
        auto k = st[i];

        if (!(k >= '1' && k <= '8')) {
            lstKek.first = '9';
            lstKek.second = 0;
            continue;
        }
        if (i != st.size() - 1 && st[i + 1] == '0') {
            lstKek.first = '9';
            lstKek.second = 0;
            continue;
        }

        __int64 addi = 1;
        for (int j = '1'; j < k; ++j) {
            addi += mp[j];
        }
        if (lstKek.first < k)
            addi -= lstKek.second;

        mp[k] += addi;
        mp[k] %= 1000000007ll;
        addi %= 1000000007ll;
        lstKek.first = k;
        lstKek.second = addi;
    }
    cout << lstKek.second << endl;

    return 0;
}