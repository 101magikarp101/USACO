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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

pll gcd_extend(ll a, ll b) {
    if (b == 0) return {1, 0};
    pll p = gcd_extend(b, a%b);
    return {p.y, p.x - a/b*p.y};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, w, b; cin >> n >> w >> b;
    if (w == 0 && b == 0) {
        cout << (n==0?1:0) << endl;
        return 0;
    } else if (w == 0) {
        cout << (n%b==0?1:0) << endl;
        return 0;
    } else if (b == 0) {
        cout << (n%w==0?1:0) << endl;
        return 0;
    }
    ll g = gcd(w, b);
    // cout << "g = " << g << endl;
    if (n % g != 0) {
        cout << 0 << endl;
        return 0;
    }
    pll p = gcd_extend(w, b);
    // cout << p.x << " " << p.y << endl;
    ll m = w/g;
    ll l = p.y;
    ll f = (l*n/g % m + m) % m;
    ll ans = (n/b-f)/m+1;
    // cout << "m = " << m << endl;
    // cout << "l = " << l << endl;
    // cout << "f = " << f << endl;
    // cout << "ans = " << ans << endl;
    cout << ans << endl;
    return 0;
}