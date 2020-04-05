#include <iostream>
using namespace std;
int board[100][100];

void print(int n) {
    for (int t=0;t<n;++t) {
        for (int j=0;j<n;++j) {
            cout << board[t][j] << " ";
        }
        cout << endl;
    }
}

bool isBoardFilled(int n, int &t, int &j) {
    for (t=0;t<n;++t) {
        for (j=0;j<n;++j) {
            if (!board[t][j]) return false;
        }
    }
    return true;
}

bool isSafe(int n, int r, int c, int v) {
    for (int t=0;t<n;++t)
        if (board[r][t] == v) return false;

    for (int t=0;t<n;++t)
        if (board[t][c] == v) return false;

    return true;
}

int tr(int n) {
    int tt = 0, jj = 0;
    int ss = 0;
    while (tt < n && jj < n) {
        ss += board[tt][jj];++tt, ++jj;
    }

    return ss;
}

int Solve(int n, int k) {
    int r, c;
    if (isBoardFilled(n, r, c)) {
        return tr(n);
    }

    for (int t=1;t<=n;++t) {
        if (isSafe(n, r, c, t)) {
            board[r][c] = t;
            if (Solve(n, k) == k) return k;
            board[r][c] = 0;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        memset(board, 0, sizeof(board));
        int n, k, ss;
        cin >> n >> k;
        int kk = Solve(n, k);
        cout << "Case #" << tt << ": ";
        if (kk == k) {
            cout << "POSSIBLE\n";
            print(n);
        } else cout << "IMPOSSIBLE\n";
    }
}
