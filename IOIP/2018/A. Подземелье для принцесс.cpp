#include <bits/stdc++.h>

using namespace std;
#define __int64 long long

const __int64 INF = 2000000000000000000;
const __int64 N = 100001;

int ar[N];


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }

    while (m--) {
        int cur;
        cin >> cur;
        int best = -1;
        int curl = k - 1;
        int curr = k;
        while (curl >= 0 || curr < n) {
            if (curl >= 0) {
                if(ar[curl]==cur)
                {
                    best=curl;
                    break;
                }
                if(best==-1 && ar[curl]>cur)
                    best=curl;
            }

            if (curr < n) {
                if(ar[curr]==cur)
                {
                    best=curr;
                    break;
                }
                if(best==-1 && ar[curr]>cur)
                    best=curr;
            }
            curr++;
            curl--;
        }

        if(best!=-1) {
            cout << best + 1 << ' ';
            ar[best]=0;
        }
            else
            cout<<-1<<' ';
    }


    return 0;
}