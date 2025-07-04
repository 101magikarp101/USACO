#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b; cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO" << "\n";
        return 0;
    }
    if (a == b) {
        cout << "YES" << "\n";
        return 0;
    }
    bool x = 0, y = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '1') {
            x = 1;
        }
        if (b[i] == '1') {
            y = 1;
        }
    }
    if (x && y) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}