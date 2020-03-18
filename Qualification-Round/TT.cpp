#include <iostream>
using namespace std;

int main() {
    freopen("in", "r", stdin);
    int n;
    cin >> n;

    for (int t=0;t < (1 << n);++t) cout << t << " ";
}

