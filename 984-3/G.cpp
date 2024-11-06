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
ll N;

ll ask(ll l, ll r) {
    cout << "xor " << l << " " << r << endl;
    cout.flush();
    ll x; cin >> x;
    return x;
}

void tell(ll x, ll y, ll z) {
    cout << "ans " << x << " " << y << " " << z << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        ll h = -1;
        for (ll i = 59; i >= 0; i--) {
            if (N & (1LL<<i)) {
                h = i;
                break;
            }
        }
        ll l = 1, r = N;
        ll a = -1, b = -1, c = -1;
        ll x = ask(1, N);
        if (x == 0) {
            ll res = -1;
            for (ll i = h; i >= 1; i--) {
                ll y = ask(1, (1LL<<i)-1);
                if (y != 0) {
                    a = y;
                    res = a;
                    l = (1LL<<i);
                    r = min((2LL<<i)-1LL, N);
                    break;
                }
            }
            while (l < r) {
                ll m = (l+r)/2;
                ll y = ask(l, m);
                if (y == 0) {
                    l = m+1;
                } else if (y == res) {
                    r = m;
                } else {
                    b = y;
                    c = res^b;
                    break;
                }
            }
            tell(a, b, c);
        } else {
            ll l1, r1, l2, r2;
            ll res1, res2;
            while (l < r) {
                ll m = (l+r)/2;
                ll y = ask(l, m);
                if (y == 0) {
                    l = m+1;
                } else if (y == x) {
                    r = m;
                } else {
                    res1 = y;
                    l1 = l;
                    r1 = m;
                    res2 = x^y;
                    l2 = m+1;
                    r2 = r;
                    break;
                }
            }
            while (l1 < r1) {
                ll m = (l1+r1)/2;
                ll y = ask(l1, m);
                if (y == 0) {
                    l1 = m+1;
                } else if (y == res1) {
                    r1 = m;
                } else {
                    a = y;
                    b = res1^y;
                    c = res2;
                    break;
                }
            }
            if (a != -1) {
                tell(a, b, c);
                continue;
            }
            while (l2 < r2) {
                ll m = (l2+r2)/2;
                ll y = ask(l2, m);
                if (y == 0) {
                    l2 = m+1;
                } else if (y == res2) {
                    r2 = m;
                } else {
                    a = y;
                    b = res2^y;
                    c = res1;
                    break;
                }
            }
            tell(a, b, c);
        }
    }
    return 0;
}