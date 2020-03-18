#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    freopen("in", "r", stdin);
    ll T, n;
    cin >> T;
    for (ll tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";
        cin >> n;
        ll a[n];
        for (int t=0;t<n;++t) cin >> a[t];

        vector<int> odd, even;
        for (int t=0;t<n;++t) {
            if (t & 1) odd.push_back(a[t]);
            else even.push_back(a[t]);
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        bool done = true;
        int oI = -1, eI = -1;
        for (int t=0;t<n;++t) {
            if (t & 1) {
                a[t] = odd[++oI];
            } else {
                a[t] = even[++eI];
            }
        }
        for (int t=0;t<n-1;++t) {
            if (a[t] > a[t+1]) {
                cout << t;
                done = false;
                break;
            }
        }
        if (done) cout << "OK";

        cout << '\n';
    }
}

