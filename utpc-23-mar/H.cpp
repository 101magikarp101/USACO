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

int N, M, Q;
string s;
int a[50005], b[50005];
int dp[50005][325];
uset<ll> st;
set<int> sizes;
vt<int> v;

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
    cin >> N >> M >> Q;
    cin >> s;
    for (int i = 0; i < M; i++) {
        string t; cin >> t;
        sizes.insert(sz(t));
        int h0 = 0, h1 = 0;
        for (int j = 0; j < sz(t); j++) {
            h0 = ad(mul(h0, 29), t[j]-'A'+1);
            h1 = ad(mul(h1, 31), t[j]-'A'+1);
        }
        ll h = (ll)h0*MOD2+(ll)h1;
        st.insert(h);
    }
    for (int x : sizes) {
        v.pb(x);
    }
    for (int i = 0; i < sz(v); i++) {
        int h0 = 0, h1 = 0;
        for (int j = 0; j < v[i]; j++) {
            h0 = ad(mul(h0, 29), s[j]-'A'+1);
            h1 = ad(mul(h1, 31), s[j]-'A'+1);
        }
        ll h = (ll)h0*MOD2+(ll)h1;
        dp[v[i]-1][i] = st.find(h) != st.end();
        for (int j = v[i]; j < N; j++) {
            dp[j][i] = dp[j-1][i];
            h0 = ad(mul(h0, 29), s[j]-'A'+1);
            h0 = sub(h0, mul(s[j-v[i]]-'A'+1, binpow(29, v[i])));
            h1 = ad(mul(h1, 31), s[j]-'A'+1);
            h1 = sub(h1, mul(s[j-v[i]]-'A'+1, binpow(31, v[i])));
            h = (ll)h0*MOD2+(ll)h1;
            dp[j][i] += st.find(h) != st.end();
        }
    }
    while (Q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = 0;
        for (int i = 0; i < sz(v); i++) {
            if (r-l+1 >= v[i]) {
                ans += dp[r][i]-(l==0 ? 0 : dp[l-1+v[i]-1][i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}