#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll l = 1;
    for (int i = 1; i <= 42; i++) {
        l = lcm(l, i);
        cout << "lcm(1, 2, ..., " << i << ") = " << l << endl;
    }
    return 0;
}