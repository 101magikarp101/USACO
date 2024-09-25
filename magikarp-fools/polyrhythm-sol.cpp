#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll N;
ll a[20];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ll l = 1;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        l = lcm(l, a[i]);
    }
    for (ll i = 0; i < l; i++) {
        bool yes = 0;
        for (int j = 1; j <= N; j++) {
            if (i%a[j] == 0) {
                yes = 1;
                break;
            }
        }
        if (yes) {
            cout << '*';
        } else {
            cout << '.';
        }
    }
    cout << endl;
    return 0;
}