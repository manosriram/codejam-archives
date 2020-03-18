#include <iostream>
#include <string>
#include <math.h>
#define ll long long
using namespace std;

ll possible(string s) {
    ll sm = 0;
    for (ll t=0;t<s.length();++t)
        sm += (s[t] == 'S');

    return sm;
}

ll check(string s) {
    ll powr = 1, sm = 0;
    for (ll t=0;t<s.length();++t) {
        if (s[t] == 'C') powr *= 2;
        else sm += powr;
    }
    return sm;
}

int main() {
    freopen("in", "r", stdin);
    ll T, d;
    string s;
    cin >> T;
    for (ll tt=1;tt<=T;++tt) {
        cin >> d >> s;
        ll ct = 0;
        ll ln = s.length();

        if (possible(s) > d)
            cout << "Case #" << tt << ": IMPOSSIBLE" << '\n';
        else {
            while (check(s) > d) {
                bool changed = false;
                for (ll t=ln-2;t>=0;--t) {
                    if (s[t] == 'C' && s[t+1] == 'S') {
                        changed = true;
                        swap(s[t], s[t+1]);
                        ++ct;
                        break;
                    }
                }
                if (!changed) break;
            }
            cout << "Case #" << tt << ": " << ct << '\n';
        }
    }
}

