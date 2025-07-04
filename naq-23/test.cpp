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

template <class T> class MinSegTree {
private:
    const T DEFAULT = std::numeric_limits<T>().max();
    vector<T> tree;
    vector<T> lz;
    int len;
public:
    MinSegTree(int len) : len(len), tree(len * 4, DEFAULT), lz(len * 4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tree[i] = std::min(tree[i * 2], tree[i * 2 + 1]);
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
        tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
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
        tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
    }
    T query(int node, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tree[node];
        if (lz[node] != DEFAULT) push(node);
        int m = (s + e) / 2;
        ll left = query(node * 2, s, m, l, r);
        ll right = query(node * 2 + 1, m + 1, e, l, r);
        return std::min(left, right);
    }
};

int T, N, Q;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    MinSegTree<int> st(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        st.set(1, 0, N-1, i, a[i]);
    }
    cin >> Q;
    while (Q--) {
        int x; cin >> x;
        if (x==0) {
            int l, r, v; cin >> l >> r >> v;
            l--; r--;
            st.update(1, 0, N-1, l, r, v);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << st.query(1, 0, N-1, l, r) << endl;
        }
        // st.print();
    }
    return 0;
}