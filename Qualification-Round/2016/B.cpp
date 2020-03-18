#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
using ll = long long;

bool allP(string s, ll n) {
    for (ll t=0;t<n;++t)
        if (s[t] == '-') return false;

    return true;
}

int main() {
    freopen("largeInB", "r", stdin);
    freopen("outB", "w", stdout);
    ll T, n;
    cin >> T;
    for (ll tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";
        
        string s;
        cin >> s;
        n = s.length();

        ll ct = 0;
        while (!allP(s, n)) {
            for (ll t=0;t<n;++t) {
                if (s[t] != s[t+1]) {
                    s[t] = (s[t] == '+') ? '-' : '+';
                    break;
                }
                s[t] = (s[t] == '+') ? '-' : '+';
            }
            ++ct;
        }
        cout << ct << '\n';
    }
}

