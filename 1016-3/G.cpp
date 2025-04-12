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

struct node {
    int v;
    bool b;
    int l = -1, r = -1;
};

int T, N, K;
int a[200005];
vt<node> tr;

void insert(int i, int x, int h, int u) {
    ckmax(tr[u].v, i);
    if (h == 0) return;
    h--;
    if ((x>>h)&1) {
        if (tr[u].r == -1) {
            tr[u].r = sz(tr);
            tr.pb({0, 1});
        }
        insert(i, x, h, tr[u].r);
    } else {
        if (tr[u].l == -1) {
            tr[u].l = sz(tr);
            tr.pb({0, 0});
        }
        insert(i, x, h, tr[u].l);
    }
}

int solve(int x, int h, int cur, int u) {
    if (h == 0) return tr[u].v;
    h--;
    bool b = ((K>>h)&1)^((x>>h)&1);
    int res = -1e9;
    if ((K>>h)&1) {
        if (b) {
            if (tr[u].r != -1) res = solve(x, h, cur, tr[u].r);
        } else {
            if (tr[u].l != -1) res = solve(x, h, cur, tr[u].l);
        }
    } else {
        if (b) {
            if (tr[u].l != -1) ckmax(res, tr[tr[u].l].v);
            if (tr[u].r != -1) ckmax(res, solve(x, h, cur, tr[u].r));
        } else {
            if (tr[u].r != -1) ckmax(res, tr[tr[u].r].v);
            if (tr[u].l != -1) ckmax(res, solve(x, h, cur, tr[u].l));
        }
    }
    // cout << "u: " << u << " x: " << x << " h: " << h << " b: " << b << " K: " << K << " res: " << res << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        tr.clear();
        tr.pb({0, 0});
        cin >> N >> K;
        rep(i,0,N) cin >> a[i];
        if (K == 0) {
            cout << 1 << endl;
            continue;
        }
        int ans = INT_MAX;
        rep(i,0,N) {
            int res = solve(a[i], 30, 0, 0);
            int d = i-res+1;
            ckmin(ans, d);
            insert(i, a[i], 30, 0);
        }
        cout << (ans > N ? -1 : ans) << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}