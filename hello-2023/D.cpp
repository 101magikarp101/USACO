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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

int T, N, M;
int a[200005], b[200005];
int c[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,0,N) cin >> a[i];
        rep(i,0,N) cin >> b[i];
        cin >> M;
        map<int,int> rz;
        rep(i,0,M) {
            cin >> c[i];
            rz[c[i]]++;
        }
        bool valid = 1;
        rep(i,0,N) {
            if (a[i] < b[i]) {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            cout << "NO" << endl;
            continue;
        }
        MaxSegTree<int> st(N);
        map<int,vt<int>,greater<int>> m;
        rep(i,0,N) {
            st.set(1,0,N-1,i,b[i]);
            if (b[i] < a[i]) m[b[i]].pb(i);
        }
        bool good = 1;
        for (auto [k,v] : m) {
            int l = v[0];
            rep(i,0,sz(v)) {
                int r = v[i];
                int mx = st.query(1,0,N-1,l,r);
                if (mx > k) {
                    rz[k]--;
                    l = r;
                }
            }
            rz[k]--;
            if (rz[k] < 0) {
                good = 0;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}