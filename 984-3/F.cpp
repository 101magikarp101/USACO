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
#define fi first
#define se second
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int T;

ll tot(ll n) {
    ll ans = ((n%4==1||n%4==2) ? 1 : 0);
    for (ll i = 1; i < 60; i++) {
        ll r = n % (2LL<<i);
        // cout << "i = " << i << ", r = " << r << endl;
        if (r >= (1LL<<i)) {
            ll res = r - (1LL<<i) + 1;
            if (res % 2) {
                ans |= (1LL<<i);
            }
        }
    }
    // cout << "tot(" << n << ") = " << ans << endl;
    return ans;
}

ll solve(ll n, ll i, ll k) {
    ll ans = tot(n);
    ll res = (n-k)/(1LL<<i);
    ans ^= tot(res)<<i;
    ll r = n % (2LL<<i);
    if (k <= r && r < (1LL<<i)+k) {
        ans ^= k;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        ll l, r, i, k; cin >> l >> r >> i >> k;
        ll lans = solve(l-1, i, k);
        ll rans = solve(r, i, k);
        cout << (rans^lans) << endl;
    }
    return 0;
}