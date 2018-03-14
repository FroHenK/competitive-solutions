#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 1000001;

int wai[1000000];//where am i
int n;

int ac1[1000000];
int n1[1000000];
int ac2[1000000];
int n2[1000000];

int lim = 0;

//vertex, side
int dfs(int v, int s) {
    if (v == lim)
        return 0;
    int l = wai[v];
    int r = wai[v + 1];
    if (l > r)
        swap(l, r);

    if (s) {
        ac1[l] = 1;
        ac1[r] = 2;
        n1[l] = v;
        n1[r] = v;
    } else {
        ac2[l] = 1;
        ac2[r] = 2;
        n2[l] = v;
        n2[r] = v;
    }

    return dfs(v + 1, !s) + 1;
}

int isPossible(int l) {
    memset(ac1, 0, sizeof ac1);
    memset(n1, 0, sizeof n1);
    memset(ac2, 0, sizeof ac2);
    memset(n2, 0, sizeof n2);

    lim = l;
    dfs(0, 0);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (ac1[i] == 1) {
            st.push(n1[i]);
        }
        if (ac1[i] == 2) {
            if (st.empty() || st.top() != n1[i]) {

                return 0;
            }
            st.pop();
        }
    }

    for (int i = 0; i < n; ++i) {
        if (ac2[i] == 1) {
            st.push(n2[i]);
        }
        if (ac2[i] == 2) {
            if (st.empty() || st.top() != n2[i]) {

                return 0;
            }
            st.pop();
        }
    }


    return 1;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif


    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        --t;
        wai[t] = i;
    }
    int l = 0;
    int r = n - 1;

    while (l < r) {
        int m = (l + r) / 2;
        if (isPossible(m + 1)) {
            l = m + 1;
        } else
            r = m;
    }
    cout<<r+1<<endl;

    return 0;
}