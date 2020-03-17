#include <iostream>
#include <string>
#include <math.h>
#define ll long long int
using namespace std;

int main() {
    ll T, n;
    cin >> T;
    for (int l=0;l<T;++l) {
        string s;
        cin >> s;
        
        string x = "";
        for (ll t=s.length() - 1;t >= 0;--t) {
            if (s[t] == '4') {
                s[t] = '3';
                // x += std::to_string(pow(10, s.length() - 1 - t));
                x += pow(10, (s.length() - 1 - t));
            }
        }
        cout << "Case #" << (l+1) << ": " << s << " " << x << '\n';
    }
}
