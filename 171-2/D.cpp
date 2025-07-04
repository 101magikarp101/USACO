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

ll N, Q;
ll a[300005], p[300005];
ll p2[300005], pp2[300005];
ll pp[300005], ppp[300005];

ll ma(ll n) {
    ll l = 0, r = N;
    while (l < r) {
        ll m = (l+r+1)/2;
        if ((N+(N-m+1))*m/2 < n) {
            l = m;
        } else {
            r = m-1;
        }
    }
    return l;
}

ll query(ll n) {
    if (n == 0) return 0;
    ll idx = ma(n);
    ll res = ppp[idx];
    n -= (N+(N-idx+1))*idx/2;
    n += idx;
    // cout << "idx: " << idx << " n: " << n << endl;
    res += pp[idx+1];
    // cout << "res: " << res << endl;
    res -= pp2[N]-pp2[n];
    // cout << "res: " << res << endl;
    res += p2[idx]*(N-idx-(n-idx));
    // cout << "res: " << res << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    p[0] = 0;
    for (ll i = 1; i <= N; i++) {
        p[i] = p[i-1]+a[i]*(N-i+1);
    }
    for (ll i = 1; i <= N; i++) {
        pp[i] = p[N]-p[i-1];
    }
    ppp[0] = 0;
    for (ll i = 1; i <= N; i++) {
        ppp[i] = ppp[i-1]+pp[i];
    }
    p2[0] = 0;
    for (ll i = 1; i <= N; i++) {
        p2[i] = p2[i-1]+a[i];
    }
    pp2[0] = 0;
    for (ll i = 1; i <= N; i++) {
        pp2[i] = pp2[i-1]+p2[i];
    }
    cin >> Q;
    while (Q--) {
        ll l, r; cin >> l >> r;
        ll rans = query(r);
        ll lans = query(l-1);
        cout << rans-lans << endl;
    }
    return 0;
}