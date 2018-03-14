#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

struct fb {
    int d, m, a, id;

    bool operator<(const fb &rhs) const {
        return id < rhs.id;
    }

    bool operator>(const fb &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const fb &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const fb &rhs) const {
        return !(*this < rhs);
    }
};

int co1(fb &a, fb &b) {
    return a.d > b.d;
}

int co2(fb &a, fb &b) {
    return a.m > b.m;
}

int co3(fb &a, fb &b) {
    return a.a > b.a;
}


struct gratak {

    bool
    operator()(const fb &__x, const fb &__y) const {
        if (__x.d == __y.d)
            return __x.id < __y.id;
        return __x.d > __y.d;
    }
};


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<fb> v1;
    vector<fb> v2;
    vector<fb> v3;
    multiset<fb, gratak> ds;
    for (int i = 0; i < n; ++i) {
        fb f{};
        cin >> f.d;
        cin >> f.m;
        cin >> f.a;
        f.id = i;
        v1.push_back(f);
        v2.push_back(f);
        v3.push_back(f);
        ds.insert(f);
    }
    set<fb> chosen;

    sort(v1.begin(), v1.end(), co1);
    sort(v2.begin(), v2.end(), co2);
    sort(v3.begin(), v3.end(), co3);
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;

//    while (k1 < 5) {
//        chosen.insert(v1[k1]);
//        k1++;
//    }

    while (k2 < 10) {
        chosen.insert(v2[k2]);
        k2++;
    }


    while (k3 < 10) {
        chosen.insert(v3[k3]);
        k3++;
    }

    int m0 = -1, m1 = -1, m2 = -1, m3 = -1, m4 = -1, m5 = -1, m6 = -1, m7 = -1, m8 = -1, m9 = -1;
    int mx = -1;

    vector<fb> c;
    for (auto i:chosen)
        c.push_back(i);

    if (c.size() < 10)
        return 1;

    for (int d0 = 0; d0 < c.size(); ++d0) {
        for (int d1 = 0; d1 < c.size(); ++d1) {
            if (d1 == d0)continue;
            for (int d2 = 0; d2 < c.size(); ++d2) {
                if (d2 == d0)continue;
                if (d2 == d1)continue;
                for (int d3 = 0; d3 < c.size(); ++d3) {
                    if (d3 == d0)continue;
                    if (d3 == d1)continue;
                    if (d3 == d2)continue;
                    for (int d4 = 0; d4 < c.size(); ++d4) {
                        if (d4 == d0)continue;
                        if (d4 == d1)continue;
                        if (d4 == d2)continue;
                        if (d4 == d3)continue;
                        int cur = 0;
                        cur += c[d0].m;
                        cur += c[d1].m;
                        cur += c[d2].m;
                        cur += c[d3].a;
                        cur += c[d4].a;
                        ds.erase(c[d0]);
                        ds.erase(c[d1]);
                        ds.erase(c[d2]);
                        ds.erase(c[d3]);
                        ds.erase(c[d4]);
                        auto itek = ds.begin();
                        auto da1=*itek;
                        itek++;
                        auto da2=*itek;
                        itek++;
                        auto da3=*itek;
                        itek++;
                        auto da4=*itek;
                        itek++;
                        auto da5=*itek;

                        cur+=da1.d;
                        cur+=da2.d;
                        cur+=da3.d;
                        cur+=da4.d;
                        cur+=da5.d;


                        if (cur > mx) {
                            m5 = c[d0].id;
                            m6 = c[d1].id;
                            m7 = c[d2].id;
                            m8 = c[d3].id;
                            m9 = c[d4].id;

                            m0 = da5.id;
                            m1 = da4.id;
                            m2 = da3.id;
                            m3 = da2.id;
                            m4 = da1.id;
                            mx = cur;
                        }


                        ds.insert(c[d0]);
                        ds.insert(c[d1]);
                        ds.insert(c[d2]);
                        ds.insert(c[d3]);
                        ds.insert(c[d4]);
                    }
                }
            }
        }
    }


    cout << m0 + 1 << ' ' << m1 + 1 << ' ' << m2 + 1 << ' ' << m3 + 1 << ' ' << m4 + 1 << endl;
    cout << m5 + 1 << ' ' << m6 + 1 << ' ' << m7 + 1 << endl;
    cout << m8 + 1 << ' ' << m9 + 1 << endl;

    return 0;
}