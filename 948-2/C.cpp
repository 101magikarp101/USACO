#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {
    ll x, y;
    bool operator<(const pll &p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

int T, N;
ll a[2005];
multiset<ll> s;
map<pll, int> m;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        s.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        ll l = 1;
        for (int i = 0; i < N; i++) {
            l = lcm(l, a[i]);
            if (l > 1e9) break;
        }
        if (s.find(l) == s.end()) {
            cout << N << "\n";
            continue;
        }
        map<ll, ll> s2;
        map<ll, ll> next;
        s2.insert({1,0});
        for (int i = 0; i < N; i++) {
            for (auto x : s2) {
                next[x.first] = x.second;
            }
            for (auto x : s2) {
                ll lc = lcm(x.first, a[i]);
                next[lc] = max(next[lc], x.second+1);
            }
            s2 = next;
            next.clear();
        }
        ll ans = 0;
        for (auto x : s2) {
            // cout << x.first << " " << x.second << "\n";
            if (s.find(x.first) == s.end()) {
                ans = max(ans, x.second);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}