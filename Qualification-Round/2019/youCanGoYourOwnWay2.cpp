#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int n, T;
    string s;
    cin >> T;
    for (int l=1;l<=T;++l) {
        cin >> n >> s;

        cout << "Case #" << l << ": ";
        for (int t=0;t<s.length();++t) {
            if (s[t] == 'S')
                cout << "E";
            else
                cout << "S";
        }
        cout << endl;
    }
}
