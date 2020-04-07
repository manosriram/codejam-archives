#include <set>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int board[100][100];
int R, C, all;
set<int> st;
map<int, pair<int, int>> mp;
int dp[20][20] = { -1 };

void print() {
    for (int t=0;t<R;++t) {
        for (int j=0;j<C;++j) {
            cout << board[t][j] << " ";
        }
        cout << endl;
    }
}

bool isBoardFilled(int &t, int &j) {
    for (t=0;t<R;++t) {
        for (j=0;j<C;++j) {
            if (board[t][j] == -1) return false;
        }
    }
    return true;
}

bool isSafe(int r, int c, int v) {
    for (int t=0;t<R;++t)
        if (abs(board[t][c] - v) <= 1) return false;

    for (int t=0;t<C;++t)
        if (abs(board[r][t] - v) <= 1) return false;

    int i = r, j = c;
    while (i >= 0 && j >= 0) {
        if (abs(board[i][j] - v) <= 1) return false;

        --i, --j;
    }

    i = r, j = c;
    while (i < R && j >= 0) {
        if (abs(board[i][j] - v) <= 1) return false;

        ++i, --j;
    }

    i = r, j = c;
    while (i >= 0 && j < C) {
        if (abs(board[i][j] - v) <= 1) return false;

        --i, ++j;
    }

    i = r, j = c;
    while (i < R && j < C) {
        if (abs(board[i][j] - v) <= 1) return false;

        ++i, ++j;
    }
    return true;
}

int Solve() {
    int r, c;
    if (isBoardFilled(r, c)) return true;

    if (dp[r][c] != -1)
        cout << dp[r][c] << endl;

    for (int t=1;t<=R*C;++t) {
        if (isSafe(r, c, t)) {
            if (st.find(t) != st.end())
                board[r][c] = t;
            else continue;

            st.erase(t);
            mp[t] = make_pair(r+1, c+1);
            ++all;
            if (Solve()) {
                return dp[r][c] = 1;
            }
            st.insert(t);
            --all;
        }
    }

    return dp[r][c] = 0;
}

int main() {
    freopen("in", "r", stdin);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        mp.clear();
        st.clear();
        all = 0;
        memset(board, -1, sizeof(board));
        memset(dp, -1, sizeof(dp));

        cin >> R >> C;
        for (int t=1;t<=R*C;++t) st.insert(t);
        Solve();

        cout << "Case #" << tt << ": ";
        if (all == 0)
            cout << "IMPOSSIBLE";
        else {
            cout << "POSSIBLE\n";
            for (int t=1;t<=R*C;++t)
                cout << mp[t].first << " " << mp[t].second << '\n';
        }
        cout << '\n';
    }
}
