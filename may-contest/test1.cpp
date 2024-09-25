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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i <= 1000000; i++) {
        ll x = 2023*i*i-i*i*i+1;
        if (x<0) continue;
        ll y = sqrt(x);
        if (y*y==x) {
            cout << i << " " << y << '\n';
        }
    }
    return 0;
}