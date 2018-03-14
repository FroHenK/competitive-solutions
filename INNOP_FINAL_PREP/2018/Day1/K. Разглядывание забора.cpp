#include <bits/stdc++.h>

#define __int64 long long

static const int COLUMN = 1;
static const int ROCK_END = 2;
static const int ROCK_START = 0;
using namespace std;
double jx, jy;
# define M_PI        3.14159265358979323846    /* pi */

long double pa(long double x, long double y) {

    swap(x, y);

    swap(jx, jy);
    long double k = atan2l(x - jx, y - jy);
    if (k < 0)
        k += M_PI * 2;

    swap(jx, jy);
    return k;
}

const long double EPS = 0.00000000000000001;

struct lesskek {

    bool
    operator()(const pair<long double, int> &a, const pair<long double, int> &b) const {
        if (abs(a.first - b.first) <= EPS)
            return a.second < b.second;
        return a < b;
    }
};

void print(double x) {
    cout << x << ' ';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    freopen("boundary.in", "r", stdin);
    freopen("boundary.out", "w", stdout);
#endif




    int n, m;
    cin >> n >> m;
    cin >> jx >> jy;
    multiset<pair<long double, int>, lesskek> events;// 1 - column, 2 - rock start, 0 - rock end
    multiset<pair<long double, int> > keks;// 1 - column, 2 - rock start, 0 - rock end

    for (int i = 0; i < n; ++i) {
        events.insert({pa(i, 0), COLUMN});
        events.insert({pa(n, i), COLUMN});
        events.insert({pa(n - i, n), COLUMN});
        events.insert({pa(0, n - i), COLUMN});
    }
    while (m--) {
        int p;
        cin >> p;
        long double mini = 100.0;
        long double maxi = 0;
        long double lst = -10;
        int bobak = 0;

        set<long double> kekas;

        while (p--) {
            double x, y;
            cin >> x >> y;
            long double cr = pa(x, y);
            kekas.insert(cr);
        }
        for (auto cr:kekas) {
            mini = min(mini, cr);
            maxi = max(maxi, cr);
            if (lst < 0)
                lst = cr;
            if (abs(lst - cr) > M_PI) {
                mini = min(lst, cr);
                maxi = max(lst, cr);
                bobak = 1;
                break;
            }
            lst=cr;
        }
        if (maxi - mini > M_PI) {
            events.insert({0, ROCK_START});
            events.insert({maxi, ROCK_START});
            events.insert({mini, ROCK_END});
            events.insert({M_PI * 2, ROCK_END});
        } else {
            events.insert({mini, ROCK_START});
            events.insert({maxi, ROCK_END});
        }
    }
    int rocks = 0;
    int suma = 0;
    for (auto i:events) {
        if (i.second == ROCK_START) {
            rocks++;
        }
        if (i.second == ROCK_END) {
            rocks--;
        }
        if (i.second == COLUMN) {
            if (!rocks)
                suma++;
        }

    }
    cout << suma << endl;
    return 0;
}