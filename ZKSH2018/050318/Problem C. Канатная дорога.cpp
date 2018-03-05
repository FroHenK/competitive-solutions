#include <bits/stdc++.h>

using namespace std;


int comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {

    return (a.second.second - a.second.first) < (b.second.second - b.second.first);
}

unsigned long kekas[256];

int countBad(string st) {
    for (unsigned  char i = 0; i < 255; ++i) {
        kekas[i] = st.rfind(i);
    }
    int suma = 0;
    for (int i = 0; i < st.size(); ++i) {
        suma += kekas[st[i]] - i;
    }
    return suma*5;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    int n;
    cin >> n;
    string st;
    cin >> st;
    string sts(st);
    sort(sts.begin(),sts.end());
    cout<<(countBad(st)-countBad(sts))<<endl;

    return 0;
}