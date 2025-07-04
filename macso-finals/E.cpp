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
    bool operator==(const pll &a) const { return x == a.x; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};
 
int T, N;
ll a[200005];
ll l[200005], r[200005];
int st[200005];
int t = -1;
pll b[200005];
umap<ll,ll> m, m2;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b, b+N);
    for (int i = 0; i < N; i++) {
        m[b[i].x] = i;
        m2[i] = b[i].x;
    }
    for (int i = 0; i < N; i++) {
        a[i] = m[a[i]];
    }
    for (int i = 0; i < N; i++) {
        while (t >= 0 && a[st[t]] >= a[i]) t--;
        l[i] = t < 0 ? -1 : st[t];
        st[++t] = i;
    }
    t = -1;
    for (int i = N-1; i >= 0; i--) {
        while (t >= 0 && a[st[t]] >= a[i]) t--;
        r[i] = t < 0 ? N : st[t];
        st[++t] = i;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll res = m2[a[i]];
        ans = max(ans, (r[i]-l[i]-1)*m2[a[i]]);
    }
    cout << ans << endl;
    return 0;
}