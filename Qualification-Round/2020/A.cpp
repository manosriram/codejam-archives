#include <iostream>
#include <map>
using namespace std;

bool isSafeC(int c, int n, int board[110][110]) {
   map<int, int> mm;
   for (int t=0;t<n;++t) {
       mm[board[t][c]]++;
   } 
   return (mm.size() == n);
}

bool isSafeR(int r, int n, int board[110][110]) {
   map<int, int> mm;
   for (int t=0;t<n;++t) {
       mm[board[r][t]]++;
   } 
   return (mm.size() == n);
}

int main() {
    int T, n, ss;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        ss = 0;
        cin >> n;
        int a[110][110];
        for (int t=0;t<n;++t) {
            for (int j=0;j<n;++j) {
                cin >> a[t][j];

                if (t == j) ss += a[t][j];
            }
        }
        int rr = 0, cc = 0;
        for (int t=0;t<n;++t) {
            if (!isSafeR(t, n, a)) ++rr;
            if (!isSafeC(t, n, a)) ++cc;
        }
        cout << "Case #" << tt << ": " << ss << " " << rr << " " << cc << '\n';
    }
}

