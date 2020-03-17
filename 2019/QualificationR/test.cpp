#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

bool Solve(int r, int c, int n, vector<int> vt, map<pair<int, int>, bool> mp) {
    if (r == n && c == n) {
        vt.clear();
        return true;
    }

    if (r > n || c > n) return false;

    if ((!mp[make_pair(r, c)]|| !mp[make_pair(r+1, c)]) && Solve(r+1, c, n, vt, mp))
        vt.push_back(r+1);
    if ((!mp[make_pair(r, c)] || !mp[make_pair(r, c+1)]) && Solve(r, c+1, n, vt, mp))
        vt.push_back(r);

    return true;
}

int main() {
    int n;
    vector<int> vt;
    int T;
    cin >> T;
    // bool visited[50000][50000];
    map<pair<int, int>, bool> mp;
    for (int l=1;l<=T;++l) {
        vt.clear();
        cin >> n;
        string s;
        cin >> s;

        int r = 1, c = 1;
        mp[make_pair(r, c)] = true;
        for (int t=0;t<s.length();++t) {
            if (s[t] == 'E') ++c;
            else ++r;

            mp[make_pair(r, c)] = true;
        }

        for (auto itr = mp.begin();itr != mp.end();++itr)
            cout << itr->first.first << " " << itr->first.second << endl;

        cout << vt.size();
        return 0;
        Solve(1, 1, n, vt, mp);
        vt.push_back(1);

        cout << "Case #" << l << ": ";
        for (int t=vt.size()-1;t>=1;--t) {
            if (vt[t] == vt[t-1]-1)
                cout << "S";
            else cout << "E";
        }
        cout << '\n';
    }
}


