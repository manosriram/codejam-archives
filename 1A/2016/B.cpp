#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    freopen("B-small-practice.in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    cin >> T;
    map<int, int> mm;
    vector<int> vv;
    for (int tt=1;tt<=T;++tt) {
        vv.clear();
        mm.clear();
        int N;
        cin >> N;
        int x;
        for (int t=0;t<(2*N)-1;++t) {
            for (int j=0;j<N;++j) {
                cin >> x;
                ++mm[x];
            }
        }
        for (int t=1;t<=2*N;++t) {
            if (mm[t] == ((t % N) * N - (t % N))) continue;
            else vv.push_back(t);
        }

        cout << "Case #" << tt << ": ";
        for (int t=0;t<vv.size();++t) cout << vv[t] << " ";

        cout << '\n';
    }
}

