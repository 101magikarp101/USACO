#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

int N, X;
ll a[45];

vt<pll> solve(int l, int r) {
    vt<pll> v;
    v.pb({0, 1});
    for (int i = l; i <= r; i++) {
        vt<pll> v2;
        each(j, v) {
            v2.pb({j.x + a[i], j.y});
        }
        vt<pll> res;
        int l = 0, r = 0;
        while (l < sz(v) && r < sz(v2)) {
            if (v[l].x == v2[r].x) {
                res.pb({v[l].x, v[l].y + v2[r].y});
                l++;
                r++;
            } else if (v[l].x < v2[r].x) {
                res.pb(v[l]);
                l++;
            } else {
                res.pb(v2[r]);
                r++;
            }
        }
        while (l < sz(v)) {
            res.pb(v[l]);
            l++;
        }
        while (r < sz(v2)) {
            res.pb(v2[r]);
            r++;
        }
        v = res;
    }
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> X;
    rep(i,0,N) cin >> a[i];
    int mid = N/2;
    vt<pll> m1 = solve(0, mid-1);
    vt<pll> m2 = solve(mid, N-1);
    int x = 0, y = sz(m2)-1;
    ll ans = 0;
    while (x < sz(m1) && y >= 0) {
        if (m1[x].x + m2[y].x == X) {
            ans += m1[x].y * m2[y].y;
            x++;
            y--;
        } else if (m1[x].x + m2[y].x < X) {
            x++;
        } else {
            y--;
        }
    }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}