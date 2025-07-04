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

struct state {
    int v, l, r;
    bool operator<(const state &a) const { return v < a.v; }
    bool operator>(const state &a) const { return v > a.v; }
};

    template <class T> class MaxSegTree {
private:
    const T DEFAULT = std::numeric_limits<T>().min();
    vector<T> tree;
    vector<T> lz;
    int len;
public:
    MaxSegTree(int len) : len(len), tree(len * 4, DEFAULT), lz(len * 4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tree[i] = std::max(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    void push(int node) {
        tree[node * 2] = lz[node];
        tree[node * 2 + 1] = lz[node];
        lz[node * 2] = lz[node];
        lz[node * 2 + 1] = lz[node];
        lz[node] = DEFAULT;
    }
    void set(int node, int s, int e, int idx, T val) {
        if (s == e) {
            tree[node] = val;
            return;
        }
        if (lz[node] != DEFAULT) push(node);
        int m = (s + e) / 2;
        if (idx <= m) {
            set(node * 2, s, m, idx, val);
        } else {
            set(node * 2 + 1, m + 1, e, idx, val);
        }
        tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
    }
    void update(int node, int s, int e, int l, int r, T val) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            tree[node] = val;
            lz[node] = val;
            return;
        }
        if (lz[node] != DEFAULT) push(node);
        int m = (s + e) / 2;
        update(node * 2, s, m, l, r, val);
        update(node * 2 + 1, m + 1, e, l, r, val);
        tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
    }
    T query(int node, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tree[node];
        if (lz[node] != DEFAULT) push(node);
        int m = (s + e) / 2;
        ll left = query(node * 2, s, m, l, r);
        ll right = query(node * 2 + 1, m + 1, e, l, r);
        return std::max(left, right);
    }
};

int T, N;
int a[200005];
pii b[200005];
int dp[200005];
pii l[200005], r[200005];
state stk[200005];
int t = -1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    rep(i,0,N) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b, b+N);
    rep(i,0,N) {
        state res = {-1,-1,-1};
        if (t != -1) {
            auto it = upper_bound(stk, stk+t+1, state{a[i],0,0}, greater<state>());
            if (it != stk+t+1) {
                res = *it;
            }
        }
        l[i] = {res.l, res.r};
        while (t != -1 && stk[t].v < a[i]) {
            t--;
        }
        if (t != -1 && stk[t].v == a[i]) {
            stk[t].r = i;
        } else {
            stk[++t] = {a[i], i, i};
        }
    }
    t = -1;
    rrep(i,N-1,0) {
        state res = {-1,-1,-1};
        if (t != -1) {
            auto it = upper_bound(stk, stk+t+1, state{a[i],0,0}, greater<state>());
            if (it != stk+t+1) {
                res = *it;
            }
        }
        r[i] = {res.l, res.r};
        while (t != -1 && stk[t].v < a[i]) {
            t--;
        }
        if (t != -1 && stk[t].v == a[i]) {
            stk[t].l = i;
        } else {
            stk[++t] = {a[i], i, i};
        }
    }
    MaxSegTree<int> dp(N);
    rep(i,0,N) {
        int idx = b[i].y;
        int left = (l[idx].x == -1 ? 0 : dp.query(1, 0, N-1, l[idx].x, l[idx].y));
        int right = (r[idx].x == -1 ? 0 : dp.query(1, 0, N-1, r[idx].x, r[idx].y));
        int res = max(left, right) + 1;
        // cout << "idx " << idx << " " << left << " " << right << " " << res << endl;
        dp.set(1, 0, N-1, idx, res);
    }
    int ans = dp.query(1, 0, N-1, 0, N-1);
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}