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

ll ad(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

ll P = 31, P2 = 37;

int N, Q;
map<ll, int> pre, suf;
map<pll, int> both;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int n = sz(s);
        ll h00 = 0, h01 = 0, h10 = 0, h11 = 0;
        for (int j = 0; j < n; j++) {
            h00 = (h00*P+s[j]-'a'+1)%MOD2;
            h01 = (h01*P2+s[j]-'a'+1)%MOD2;
            h10 = ad(h10, mul(binpow(P, j), s[n-1-j]-'a'+1));
            h11 = ad(h11, mul(binpow(P2, j), s[n-1-j]-'a'+1));
            ll h0 = h00*MOD2+h01, h1 = h10*MOD2+h11;
            pre[h0]++;
            suf[h1]++;
            both[{h0,h1}]++;
        }
    }
    while (Q--) {
        string t, a, b; cin >> t >> a >> b;
        ll h00 = 0, h01 = 0, h10 = 0, h11 = 0;
        int n = sz(a);
        for (int i = 0; i < n; i++) {
            h00 = ad(h00, mul(binpow(P, n-1-i), a[i]-'a'+1));
            h01 = ad(h01, mul(binpow(P2, n-1-i), a[i]-'a'+1));
            h10 = ad(h10, mul(binpow(P, n-1-i), b[i]-'a'+1));
            h11 = ad(h11, mul(binpow(P2, n-1-i), b[i]-'a'+1));
        }
        ll h0 = h00*MOD2+h01, h1 = h10*MOD2+h11;
        int pr = pre[h0];
        int su = suf[h1];
        int bo = both[{h0,h1}];
        if (t == "AND") {
            cout << bo << endl;
        } else if (t == "OR") {
            cout << pr+su-bo << endl;
        } else {
            cout << pr+su-2*bo << endl;
        }
    }
    return 0;
}