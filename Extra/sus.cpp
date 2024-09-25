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
    ll n; cin >> n;
    if (n < 13) {
        cout << (1LL<<n) << endl;
    } else {
        cout << 8092LL*(1LL<<(n-13)) << endl;
    }
    return 0;
}