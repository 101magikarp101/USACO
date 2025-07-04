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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

struct frac {
    ll n, d;
    frac red() {
        ll g = gcd(n,d);
        return {n/g,d/g};
    }
    frac operator-(const frac &a) const { 
        frac res = {n*a.d-d*a.n,d*a.d};
        return res.red();
    }
    frac operator+(const frac &a) const { 
        frac res = {n*a.d+d*a.n,d*a.d};
        return res.red();
    }
    frac operator*(const ll &a) const { 
        frac res = {n*a,d};
        return res.red();
    }
    frac operator/(const ll &a) const { 
        frac res = {n,d*a};
        return res.red();
    }
    bool operator>(const frac &a) const {
        return n*a.d > d*a.n;
    }
    bool operator<(const frac &a) const {
        return n*a.d < d*a.n;
    }
    bool operator<=(const frac &a) const {
        return n*a.d <= d*a.n;
    }
    bool operator>=(const frac &a) const {
        return n*a.d >= d*a.n;
    }
};

bool solve (int l, frac f1, frac f2, frac f3) {
    if (l == 0) return 0;
    frac o = {1,3}, t = {2,3};
    bool b1 = f1 > o && f1 < t;
    bool b2 = f2 > o && f2 < t;
    bool b3 = f3 > o && f3 < t;
    if (b1&&b2 || b2&&b3 || b1&&b3) {
        return 1;
    }
    while (f1 >= o) {
        f1 = f1 - o;
    }
    while (f2 >= o) {
        f2 = f2 - o;
    }
    while (f3 >= o) {
        f3 = f3 - o;
    }
    return solve(l-1,f1*3,f2*3,f3*3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll l; cin >> l;
    frac f1, f2, f3;
    cin >> f1.n >> f1.d >> f2.n >> f2.d >> f3.n >> f3.d;
    bool ans = solve(l, f1, f2, f3);
    cout << !ans << endl;
    return 0;
}