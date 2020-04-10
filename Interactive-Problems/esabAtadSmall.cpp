#include <iostream>
#include <vector>
using namespace std;
int B = 4;

int query(int in) {
    cout << in << endl;
    int ret;
    cin >> ret;
    return ret;
}

vector<int> Solve() {
    int n = 100;
    vector<int> answer(B);
    int qrs = 0;
    for (int t=0;t<B;++t) {
        answer[t] = query(t);
        ++qrs;

        if (qrs % 2 == 0) {
            if (answer[0] != query(0)) {
                for (int j=0;j<=t;++j) {
                    answer[j] ^= 1;
                }
                ++qrs;
            }
        }
    }
    return answer;
}

int main() {
    auto answer = Solve();
    for (int t=0;t<B;++t) cout << answer[t] << " ";
}
