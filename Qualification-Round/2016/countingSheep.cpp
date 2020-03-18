#include <iostream>
#include <map>
#define ll long long
using namespace std;

int main() {
    freopen("largein", "r", stdin);
    freopen("out", "w", stdout);
    ll T;
    cin >> T;
    for (ll tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";

        ll n, m;
        cin >> n;
        if (n == 0) {
            cout << "INSOMNIA" << '\n';
            continue;
        }
        m = n;

        bool a[10];
        memset(a, false, sizeof(a));
        ll ct = 0;
        ll run = 1;

        while (ct <= 9) {
            while (n > 0) {
                int num = n % 10;
                if (!a[num])
                    ++ct;

                a[num] = true;
                n /= 10; 
            }           
            n = m * ++run;
        }
        cout << n - m << '\n';
    }
}
