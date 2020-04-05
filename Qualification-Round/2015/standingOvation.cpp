#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
using ll = long long;

int main() {
    freopen("smallIn", "r", stdin);
    freopen("outA", "w", stdout);
    ll T, n;
    cin >> T;
    for (ll tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";
        string s;
        cin >> n >> s;

        ll ct = 0;
        for (ll t=0;t<n;++t) ct += s[t] == '0';

        cout << ct << '\n';
    }
}

