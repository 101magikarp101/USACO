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

void brute(ll cur, ll sum, ll ssq, ll n) {
    if (cur == 975) return;
    // cout << sum*sum-ssq << endl;
    if (n == 0) {
        if (sum*sum-ssq == 2*MOD2) {
            cout << sum << ' ' << ssq << endl;
            cerr << sum << ' ' << ssq << endl;
        }
    }
    else {
        for (ll i = 0; i <= n; i++) {
            brute(cur-1, sum+i*cur, ssq+i*i*cur, n-i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    brute(990, 0, 0, 46);
    return 0;
}