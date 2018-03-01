//#pragma comment(linker, "stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>


using namespace std;
#define __int64 __int64_t


int mat[201][201];

int main() {

#ifdef DEBUG
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

#else
                                                                                                                            //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
#endif
    vector<int> vc;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        vc.push_back(t);
    }
    vc.push_back(vc[0]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            mat[i][j] = t;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][k] == -1 || mat[k][j] == -1)
                    continue;
                if ((mat[i][j] == -1) || (mat[i][k] + mat[k][j] < mat[i][j]))
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }
    int suma = 0;

    for (int i = 1; i < vc.size(); ++i) {
        suma += mat[vc[i - 1]][vc[i]];
        if(mat[vc[i - 1]][vc[i]]==-1)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<suma<<endl;
    return 0;
}