#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ll T;
    cin >> T;
    for (ll tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";
        string s;
        cin >> s;
        ll ln = s.length();

        bool is = true;
        for (int t=ln-1;t>=1;--t) {
            if (s[t] < s[t-1]) {
                s[t-1] -= 1;
                for (ll ml=t;ml<ln;++ml) s[ml] = '9';
            }
        }
        if (s[0] == '0')
            s = s.substr(1, ln);

        cout << s << '\n';
    }
}

