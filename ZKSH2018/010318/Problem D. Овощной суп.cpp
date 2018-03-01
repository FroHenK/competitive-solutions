//#pragma comment(linker, "stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>


using namespace std;
#define __int64 __int64_t

vector<double> st;
double T;
int n;

int lc = 500;//left cuts

void check(int mini) {
    lc = 500;
    int minl = mini;
    int minr = static_cast<int>(mini / T);

    for (auto id:st) {
        bool isGood = false;
        for (int i = 0; i <= lc; ++i) {
            if (id / (i + 1) >= minl && id / (i + 1) <= minr) {
                isGood = true;
                lc -= i;
                break;
            }
        }
        if (!isGood)
            return;
    }
    //cout<<mini<<' '<< (500-lc)<<endl;
    cout<<(500-lc)<<endl;
    exit(0);
}


int main() {

#ifdef DEBUG
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

#else
    //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
#endif
    cin >> T >> n;

    while (n--) {
        double t;
        cin >> t;
        st.push_back(t);
    }
    sort(st.begin(), st.end());
    reverse(st.begin(), st.end());
    for (auto mini = static_cast<int>(*min_element(st.begin(), st.end())); mini > 0; --mini) {
        check(mini);
    }

    return 0;
}