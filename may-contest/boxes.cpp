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
    string s, t; cin >> s >> t;
    ll n = 0, m = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i]=='#') {
            n++;
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i]=='#') {
            m++;
        }
    }
    cout << max(n, m) << " " << n*m << '\n';
    return 0;
}