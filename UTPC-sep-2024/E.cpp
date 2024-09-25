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

ll N, D, X;
ll a[200005];
ll b[200005];
ll c[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> D >> X;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < N; i++) {
        c[b[i]] += a[i];
    }
    mset<ll> s;
    ll ans = 0;
    for (ll i = 0; i < X; i++) {
        s.insert(0);
    }
    for (ll i = 200000; i >= 1; i--) {
        if (s.empty()) break;
        ll p = *s.begin();
        s.erase(s.begin());
        ll hm = min(D-p, c[i]);
        if (hm < c[i]) {
            ll req = c[i]-hm;
            while (!s.empty()) {
                ll q = *s.begin();
                ll dif = min(p, D-q);
                ll take = min(req, dif);
                req -= take;
                p -= take;
                q += take;
                if (q == D) {
                    s.erase(s.begin());
                }
                if (req == 0) {
                    break;
                }
            }
        }
        hm = min(D-p, c[i]);
        // if (hm != 0) {
        //     cout << i << " " << hm << endl;
        // }
        p += hm;
        ans += hm*i;
        if (p < D) s.insert(p);
    }
    cout << ans << endl;
    return 0;
}