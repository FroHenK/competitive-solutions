#include <bits/stdc++.h>


#define __int64 long long

void kek_solve();

using namespace std;
string st;
int n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    srand(228);


    cin >> st >> n;
    vector<string> ks;

//    if (st.size() >= 22) {
//        cout << "ABCD" << endl;
//        return 0;
//    }
    multiset<__int64> sta;
    for (int i = 2; i <= st.size(); ++i) {
        int tp = i;
        auto staas = static_cast<int>(sqrt(i) + 1);
        for (int j = 2; j < staas; ++j) {
            while (tp % j == 0) {
                sta.insert(j);
                tp /= j;
            }

        }
        if (tp != 1)
            sta.insert(tp);
    }
    for (int i = 2; i <= n; ++i) {
        int tp = i;
        auto staas = static_cast<int>(sqrt(i) + 1);
        for (int j = 2; j < staas; ++j) {
            while (tp % j == 0) {
                sta.erase(sta.find(j));
                tp /= j;
            }

        }
        if (tp != 1)
            sta.erase(sta.find(tp));
    }
    for (int i = 2; i <= (st.size() - n); ++i) {
        int tp = i;
        auto staas = static_cast<int>(sqrt(i) + 1);
        for (int j = 2; j < staas; ++j) {
            while (tp % j == 0) {
                sta.erase(sta.find(j));
                tp /= j;
            }

        }
        if (tp != 1)
            sta.erase(sta.find(tp));
    }
    __int64 k = 1;
    for (auto i:sta) {
        k *= i;
        if (k >= 500000) {

            kek_solve();
            //cout << "NO" << endl;
            return 0;
        }
    }

    vector<int> vc;
    for (int i = 0; i < st.size() - n; ++i) {
        vc.push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        vc.push_back(1);
    }

    map<__int64, int> mp;
    do {
        __int64 hs = 0;
        for (int i = 0; i < st.size(); ++i) {
            if (vc[i])
                hs = (st[i] - 'a' + hs) * 29;
        }
        mp[hs]++;
    } while (next_permutation(vc.begin(), vc.end()));


    int mx = -1;
    int suma = 0;


    for (auto i:mp) {
        mx = max(mx, i.second);
        suma += (i.second);

    }
    if (mx * 2 >= (suma))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

char bu[2000];

void kek_solve() {
    vector<int> vc;
    for (int i = 0; i < st.size() - n; ++i) {
        vc.push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        vc.push_back(1);
    }
    map<__int64, int> mp;
    int kekmem = static_cast<int>(11000000 / (st.size() * 2));;
    do {
        random_shuffle(vc.begin(), vc.end());
        __int64 hs = 0;
        for (int i = 0; i < st.size(); ++i) {
            if (vc[i])
                hs = (st[i] - 'a' + hs) * 29;
        }
        mp[hs]++;
    } while (kekmem--);


    int mx = -1;
    int suma = 0;


    for (auto i:mp) {
        mx = max(mx, i.second);
        suma += (i.second);

    }
    if (mx * 2 >= (suma))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}