#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

bool overlaps(int x1, int x2, int y1, int y2) {
    return (x1 < y2 && y1 < x2);
}

bool par(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    return (a.second.first < b.second.first);
}

int main() {
    int n, st, ed, T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";
        cin >> n;
        vector<pair<int, pair<int, int>>> vv;

        for (int t=0;t<n;++t) {
            cin >> st >> ed;
            vv.pb(make_pair(t, make_pair(st, ed)));
        }

        sort(vv.begin(), vv.end(), par);
        pair<int, int> c(INT_MAX, INT_MAX), j(INT_MAX, INT_MAX);

        bool dn = true;
        char s[n];
        for (int t=0;t<n;++t) {
            if (!overlaps(vv[t].second.first, vv[t].second.second, c.first, c.second)) {
                c.first = vv[t].second.first, c.second = vv[t].second.second;
                s[vv[t].first] = 'C';
            } else if (!overlaps(vv[t].second.first, vv[t].second.second, j.first, j.second)) {
                j.first = vv[t].second.first, j.second = vv[t].second.second;
                s[vv[t].first] = 'J';
            } else {
                dn = false;
                break;
            }
        }
        if (!dn) cout << "IMPOSSIBLE\n";
        else cout << s << '\n';
    }
}
