#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

ll T;
ll x, y, z, k;

ll solve(ll a, ll b) {
    ll cost = x*a+y*b;
    ll dam = 0;
    ll cur = 0;
    ll sec = min(b, a/k);
    cur += sec*k;
    dam += sec*(sec+1)/2*k;
    // cout << "a: " << a << " " << b << endl;
    // cout << "sec: " << sec << " " << dam << endl;
    a -= sec*k;
    b -= sec;
    cur += a;
    dam += b*cur;
    if (dam >= z) return cost;
    else return 1e18;
}

ll solvea(ll a) {
    ll l = 1, r = 1e8;
    while (l < r) {
        ll m = (l+r)/2;
        ll res = solve(a, m);
        if (res < 1e18) r = m;
        else l = m+1;
    }
    return solve(a, l);
}

ll solveb(ll b) {
    ll l = 1, r = 1e8;
    while (l < r) {
        ll m = (l+r)/2;
        ll res = solve(m, b);
        if (res < 1e18) r = m;
        else l = m+1;
    }
    return solve(l, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> x >> y >> z >> k;
        ll ans = 1e18;
        for (ll a = 1; a*a <= 2*z; a++) {
            ll res = solvea(a);
            // cout << "a: " << a << " " << res << endl;
            ans = min(ans, res);
        }
        for (ll b = 1; b*b <= 2*z; b++) {
            ll res = solveb(b);
            // cout << "b: " << b << " " << res << endl;
            ans = min(ans, res);
        }
        cout << ans << endl;
    }
    return 0;
}