#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n;
bool visited[50000][50000];
vector<int> vt;

bool Solve(int r, int c) {
    if (r == n && c == n) {
        vt.clear();
        return true;
    }

    if (r > n || c > n) return false;

    if ((!visited[r][c] || !visited[r+1][c]) && Solve(r+1, c))
        vt.push_back(r+1);
    if ((!visited[r][c] || !visited[r][c+1]) && Solve(r, c+1))
        vt.push_back(r);

    return true;
}

int main() {
    freopen("in.txt", "r", stdin);

    int T;
    cin >> T;
    for (int l=1;l<=T;++l) {
        vt.clear();
        cin >> n;
        string s;
        cin >> s;

        for (int t=1;t<=n;++t) {
            for (int j=1;j<=n;++j) {
                visited[t][j] = 0;
            }
        }

        int r = 1, c = 1;
        visited[r][c] = 1;
        for (int t=0;t<s.length();++t) {
            if (s[t] == 'E') ++c;
            else ++r;

            visited[r][c] = 1;
        }

        Solve(1, 1);
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

