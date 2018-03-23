#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;

int ar[200001];
int prne[200001];
int ne[200001];

int getNe(int l, int r) {
    return prne[r] - prne[l];
}

int prtw[200001];
int tw[200001];

int getTw(int l, int r) {
    return prtw[r] - prtw[l];
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
    int lans = -1;
    int rans = -1;
    int mxi = -3;
    set<int> zs;
    set<int> nes;
    int nesek = 0;
    int twosek = 0;

    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        prne[i] = nesek;
        prtw[i] = twosek;
        if (ar[i] > mxi) {
            lans = i;
            rans = i + 1;
            mxi = ar[i];
        }

        if (ar[i] == 2 || ar[i] == -2) {
            tw[i] = 1;
            twosek++;
        }

        if (ar[i] == 0)
            zs.insert(i);

        if (ar[i] < 0) {
            nes.insert(i);
            nesek++;
            ne[i] = 1;
        }
    }
    prne[n] = nesek;
    prtw[n] = twosek;
    zs.insert(n);
    zs.insert(-1);

    auto cur = ++zs.begin();
    int mxZs = 0;
    if (ar[lans] <= 0)
        mxZs = -1;

    while (cur != zs.end()) {
        auto r = *cur;
        cur--;
        auto l = *cur;
        cur++;
        l++;
        if (r - l <= 1) {
            cur++;
            continue;
        }
        if (getNe(l, r) % 2 == 0) {
            if (getTw(l, r) > mxZs) {
                lans = l;
                rans = r;
                mxZs = getTw(l, r);
            }
            cur++;
            continue;
        } else {
            int l1 = *nes.lower_bound(l);
            l1++;
            int r1 = r;
            if (getTw(l1, r1) > mxZs) {
                lans = l1;
                rans = r1;
                mxZs = getTw(l1, r1);
            }
            l1 = l;
            r1 = *(--nes.lower_bound(r));
            if (getTw(l1, r1) > mxZs) {
                lans = l1;
                rans = r1;
                mxZs = getTw(l1, r1);
            }
        }

        cur++;
    }


    cout << lans + 1 << ' ' << rans << endl;
    return 0;
}
