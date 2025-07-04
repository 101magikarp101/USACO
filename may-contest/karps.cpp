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
    double n, l, v; cin >> n >> l >> v;
    cout << scientific << setprecision(8) << l/v*n/(n+1) << '\n';
    return 0;
}