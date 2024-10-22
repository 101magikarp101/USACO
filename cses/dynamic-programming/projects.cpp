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

struct seg {
    int l, r;
    ll v;
};

int N;
seg a[200005];
ll dp[400005];
vt<seg> segs[400005];
map<int,int> m;
map<int,int> rm;
vt<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int l,r; ll v; cin >> l >> r >> v;
        a[i] = {l,r,v};
        s.pb(l);
        s.pb(r);
    }
    sort(all(s));
    for (int i = 0; i < s.size(); i++) {
        m[s[i]] = i+1;
        rm[i+1] = s[i];
    }
    for (int i = 0; i < N; i++) {
        a[i].l = m[a[i].l];
        a[i].r = m[a[i].r];
        segs[a[i].r].pb(a[i]);
    }
    ll ans = 0;
    dp[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i-1];
        for (seg j : segs[i]) {
            dp[i] = max(dp[i], dp[j.l-1]+j.v);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}