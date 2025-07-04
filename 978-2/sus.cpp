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

int T, N;
ll X;
map<ll,ll> m;
vt<pll> v;

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

int solve(pll p) {
    ll l = p.x, r = p.y;
    ll curl = (X+1)/2, curr = X-1;
    int res = 0;
    int cnt = 1;
    while (curr >= l) {
        ll right = min(curr, r);
        ll left = max(curl, l);
        if (left <= right) {
            res = ad(res, mul(cnt, (right-left+1)%MOD2));
        }
        curr = curl-1;
        curl = (curl+1)/2;
        cnt++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        m.clear();
        v.clear();
        for (int i = 0; i < N; i++) {
            ll l, r; cin >> l >> r;
            r++;
            m[l]++;
            m[r]--;
        }
        ll l = -1;
        ll tot = 0;
        for (auto &x : m) {
            tot += x.second;
            if (l != -1 && tot <= 0) {
                v.pb({l, x.first-1});
                l = -1;
            } else if (l == -1 && tot > 0) {
                l = x.first;
            }
        }
        int ans = 0;
        for (int i = 0; i < sz(v); i++) {
            ans = ad(ans, solve(v[i]));
        }
        cout << ans << endl;
    }
    return 0;
}