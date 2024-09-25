#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b; cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }
    int res = a.compare(b);
    if (res < 0) {
        cout << -1 << "\n";
    } else if (res > 0) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}