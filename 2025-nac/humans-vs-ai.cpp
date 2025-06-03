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

template <class T> class BIT {
    // MUST be 1-indexed
public:
    vector<T> bit;
    int size;
    BIT(int n) {size = n; bit = vector<T>(n+1, 0);}
    void upd(int i, T x) {
        for (; i <= size; i += i & -i) bit[i] += x;
    }
    // returns sum of [1, i]
    T sum(int i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    // returns sum of [l, r]
    T sum(int l, int r) {
        return sum(r) - (l>1 ? sum(l-1) : 0);
    }
};

int N;
ll K;
ll h[200005], a[200005], w[200005], u[200005];
ll pre[200005];

ll solve(int l, int r) {
    if (l == r) {
        return w[l] >= (K+1)*u[l];
    }
    int m = (l+r)/2;
    ll ans = solve(l, m) + solve(m+1, r);
    vt<ll> vr, vl;
    rep(i,l,m+1) {
        vl.pb(pre[i-1]);
    }
    rep(i,m+1,r+1) {
        vr.pb(pre[i]);
    }
    sort(all(vl));
    sort(all(vr));
    // vl.erase(unique(all(vl)), vl.end());
    // vr.erase(unique(all(vr)), vr.end());
    int n = sz(vr);
    BIT<ll> bit(n);
    ll ma = -1e9;
    int j = m+1;
    rrep(i,m,l) {
        ckmax(ma, u[i]);
        while (j <= r && u[j] <= ma) {
            int idx = lower_bound(all(vr), pre[j]) - vr.begin();
            bit.upd(idx+1, 1);
            j++;
        }
        ll tar = (K+1)*ma + pre[i-1];
        int idx = lower_bound(all(vr), tar) - vr.begin();
        if (idx < n) {
            ans += bit.sum(idx+1, n);
        }
    }
    // right side
    n = sz(vl);
    bit = BIT<ll>(n);
    ma = -1e9;
    j = m;
    rep(i,m+1,r+1) {
        ckmax(ma, u[i]);
        while (j >= l && u[j] < ma) {
            int idx = lower_bound(all(vl), pre[j-1]) - vl.begin();
            bit.upd(idx+1, 1);
            j--;
        }
        ll tar = pre[i] - (K+1)*ma;
        int idx = upper_bound(all(vl), tar) - vl.begin() - 1;
        if (idx >= 0) {
            ans += bit.sum(idx+1);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> K;
    rep(i,1,N+1) cin >> h[i];
    rep(i,1,N+1) {
        cin >> a[i];
        ll v = h[i]-a[i];
        u[i] = max(0LL, v);
        w[i] = (v>=0 ? v : K*v);
        pre[i] = pre[i-1] + w[i];
    }
    ll ans = solve(1, N);
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}