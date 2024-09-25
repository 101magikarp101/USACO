#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        ll g = gcd(x, y);
        ll lcm = x*y/g;
        cout << min(x+y, lcm) << endl;
    }
    return 0;
}