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

int N;
uset<ll> s;

int ad(int a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD2;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD2);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD2-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string st; cin >> st;
        if (i == 0) {
            ll h0 = 0, h1 = 0;
            for (int j = 0; j < sz(st); j++) {
                h0 = ad(mul(h0, 31), st[j]-'a'+1);
                h1 = ad(mul(h1, 37), st[j]-'a'+1);
            }
            ll h = h0*MOD2+h1;
            s.insert(h);
        } else {
            ll h0 = 0, h1 = 0;
            for (int j = 0; j < sz(st); j++) {
                h0 = ad(mul(h0, 31), st[j]-'a'+1);
                h1 = ad(mul(h1, 37), st[j]-'a'+1);
            }
            ll h = h0*MOD2+h1;
            bool good = 0;
            if (s.count(h)) good = 1;
            for (int cnt = 0; cnt < sz(st); cnt++) {
                h0 = sub(h0, mul(st[cnt]-'a'+1, binpow(31, sz(st)-1)));
                h0 = mul(h0, 31);
                h0 = ad(h0, st[cnt]-'a'+1);
                h1 = sub(h1, mul(st[cnt]-'a'+1, binpow(37, sz(st)-1)));
                h1 = mul(h1, 37);
                h1 = ad(h1, st[cnt]-'a'+1);
                ll h2 = h0*MOD2+h1;
                if (s.count(h2)) good = 1;
            }
            if (!good) {
                s.insert(h);
            }
        }
    }
    cout << sz(s) << endl;
    return 0;
}