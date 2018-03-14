#include <bits/stdc++.h>


#define __int64 long long

using namespace std;

const int N = 100001;


vector<__int128> vc00;
vector<__int128> vc01;

vector<__int128> vc10;
vector<__int128> vc11;

string st, sk, tk;


int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#else
    //    freopen("football.in", "r", stdin);
    //    freopen("football.out", "w", stdout);
#endif
    __int64 k, n;
    cin >> k >> n;
    cin >> st >> sk >> tk;
    int ofz = 0, zfz = 0;//ones from zeroes, zeroes from zeroes
    int ofo = 0, zfo = 0;//ones from ones, zeroes from ones
    for (auto i:sk) {
        if (i == '0')
            zfz++;
        else
            ofz++;
    }
    for (auto i:tk) {
        if (i == '0')
            zfo++;
        else
            ofo++;
    }


    {
        __int128 k0 = 1;
        __int128 k1 = 0;
        vc00.push_back(k0);
        vc01.push_back(k1);

        for (int i = 0; i < k; ++i) {
            __int128 nk0 = k0 * zfz + k1 * zfo;
            __int128 nk1 = k0 * ofz + k1 * ofo;
            k0 = nk0;
            k1 = nk1;
            if (k0 > 1000000000000000000ll)
                k0 = 1000000000000000001ll;

            if (k1 > 1000000000000000000ll)
                k1 = 1000000000000000001ll;
            vc00.push_back(k0);
            vc01.push_back(k1);
        }
    }


    {
        __int128 k0 = 0;
        __int128 k1 = 1;
        vc10.push_back(k0);
        vc11.push_back(k1);

        for (int i = 0; i < k; ++i) {
            __int128 nk0 = k0 * zfz + k1 * zfo;
            __int128 nk1 = k0 * ofz + k1 * ofo;
            k0 = nk0;
            k1 = nk1;
            if (k0 > 1000000000000000000ll)
                k0 = 1000000000000000001ll;

            if (k1 > 1000000000000000000ll)
                k1 = 1000000000000000001ll;
            vc10.push_back(k0);
            vc11.push_back(k1);
        }
    }

    reverse(vc00.begin(), vc00.end());
    reverse(vc01.begin(), vc01.end());
    reverse(vc11.begin(), vc11.end());
    reverse(vc10.begin(), vc10.end());
    string *cur = &st;

    int lvl = 0;
    __int64 curOnes = 0;
    __int64 curpos = 0;

    while (lvl <= k) {
        __int128 internalOnes = curOnes;
        unsigned long internal = 0;
        internalOnes += cur->operator[](internal) == '0' ? vc01[lvl] : vc11[lvl];
        while (internalOnes < n) {
            curpos += cur->operator[](internal) == '0' ? vc01[lvl] : vc11[lvl];
            curpos += cur->operator[](internal) == '0' ? vc00[lvl] : vc10[lvl];

            internal++;
            internalOnes += cur->operator[](internal) == '0' ? vc01[lvl] : vc11[lvl];
        }
        curOnes = static_cast<long long int>(internalOnes - (cur->operator[](internal) == '0' ? vc01[lvl] : vc11[lvl]));
        cur = cur->operator[](internal) == '0' ? &sk : &tk;

        lvl++;
    }
    cout<<curpos+1<<endl;
    return 0;
}