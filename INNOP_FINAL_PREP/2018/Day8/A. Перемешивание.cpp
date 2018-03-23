#include <bits/stdc++.h>

using namespace std;
#define __int64 long long


int lal;

int compa(vector<int> a, vector<int> b) {
    return a.size() > b.size();
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int n;
    cin >> n;
    string st;
    cin >> st;
    string resa(st);

    map<char, vector<int> > mp1;
    for (auto i:st) {
        mp1[i].push_back(lal);
        lal++;
    }

    vector<int> mp[26];
    for (auto i:mp1) {
        mp[i.first - 'a'] = i.second;
    }
    sort(mp, mp + 26, compa);
    for (int i = 0; i < 26; ++i) {
        int keka = 0;


        for (int j = 25; j >= 0; --j) {
            if (i == j)
                continue;
            vector<int> &a = mp[i];
            vector<int> &b = mp[j];

            while (!a.empty() && !b.empty()) {
                int &i1 = a.back();
                int &i2 = b.back();
                swap(resa[i1], resa[i2]);
                a.pop_back();
                b.pop_back();
            }
        }
    }


    for (auto i:mp) {
        if (!i.empty()) {
            char k = st[i[0]];
            for (int j = 0; j < st.size(); ++j) {
                if (i.empty())
                    break;
                if (st[j] != k && resa[j] != k) {
                    swap(resa[i.back()], resa[j]);
                    i.pop_back();
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (resa[i] == st[i]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << resa << endl;

    return 0;
}