#include <iostream>
using namespace std;

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        string s;
        cin >> s;
        string res;
        res += s[0];
        for (int t=1;t<s.length();++t) {
            if (s[t] >= res[0])
               res = s[t] + res;
            else res += s[t]; 
        }
        cout << "Case #" << tt << ": ";
        cout << res << '\n';
    }
}

