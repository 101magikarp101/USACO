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

string s;

ll add(ll a, ll b) {
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

ll safe(ll a) {
    return (a+MOD2)%MOD2;
}

ll has(vt<int> v) {
    ll res = 0;
    for (int i = 0; i < sz(v); i++) {
        res = add(res, mul(safe(v[i]-v[0]), binpow(107,i)));
    }
    ll res1 = 0;
    for (int i = 0; i < sz(v); i++) {
        res1 = add(res1, mul(safe(v[i]-v[0]), binpow(103,i)));
    }
    return res*MOD2+res1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    set<int> st;
    vt<int> ord(26);
    for (int i = 0; i < sz(s); i++) {
        st.insert(s[i]-'a');
    }
    int temp = 0;
    for (int i : st) {
        ord[i] = temp++;
    }
    int N = sz(s);
    int n = sz(st);
    ll ans = 0;
    vt<int> cnt(n);
    umap<ll,ll> m;
    m[0] = 1;
    for (int i = 0; i < N; i++) {
        cnt[ord[s[i]-'a']]++;
        ll h = has(cnt);
        if (m.find(h) != m.end()) {
            ans += m[h];
        }
        m[h]++;
    }
    cout << ans << endl;
    return 0;
}