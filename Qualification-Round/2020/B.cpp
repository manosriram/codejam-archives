#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        string s, rs;
        cin >> s;
        int n = s.length();
        for (int t=0;t<(s[0] - '0');++t) rs += '(';

        for (int t=0;t<n-1;++t) {
            rs += s[t];
            int aa = s[t+1] - '0', bb = s[t] - '0';
            if (aa > bb) {
                for (int j=0;j<aa-bb;++j) rs += '(';
            } else {
                for (int j=0;j<bb-aa;++j) rs += ')';
            }
        }
        rs += s[n-1];
        for (int t=0;t<s[n-1]-'0';++t) rs += ')';

        cout << "Case #" << tt << ": ";
        cout << rs << '\n';
    }
}
