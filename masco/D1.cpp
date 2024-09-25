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

int N, Q;
// ll tree[400005], lz[400005];
ll a[100005];

// void push(int node) {
//     lz[2*node] += lz[node]; lz[2*node+1] += lz[node];
//     tree[2*node] += lz[node]; tree[2*node+1] += lz[node];
//     lz[node] = 0;
// }

// //segment tree with range addition and range max
// void update(int node, int start, int end, int l, int r, ll val) {
//     if (start > r || end < l) return;
//     if (start >= l && end <= r) {
//         tree[node] += val;
//         lz[node] += val;
//         return;
//     }
//     if (lz[node]) push(node);
//     int mid = (start + end) / 2;
//     update(node*2, start, mid, l, r, val);
//     update(node*2+1, mid+1, end, l, r, val);
//     tree[node] = min(tree[node*2], tree[node*2+1]);
// }

// ll query(int node, int start, int end, int qs, int qe) {
//     if (start > qe || end < qs) return LLONG_MAX;
//     if (start >= qs && end <= qe) return tree[node];
//     if (lz[node]) push(node);
//     int mid = (start + end) / 2;
//     ll lres = query(node*2, start, mid, qs, qe);
//     ll rres = query(node*2+1, mid+1, end, qs, qe);
//     return min(lres, rres);
// }

// void build(int node, int start, int end) {
//     if (start > end) return;
//     if (start == end) {
//         tree[node] = a[start];
//         return;
//     }
//     int mid = (start + end) / 2;
//     build(node*2, start, mid);
//     build(node*2+1, mid+1, end);
//     tree[node] = min(tree[node*2], tree[node*2+1]);
// }

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
        tree[node * 2] = min(tree[node * 2], lz[node]);
        tree[node * 2 + 1] = min(tree[node * 2 + 1], lz[node]);
        lz[node * 2] = min(lz[node * 2], lz[node]);
        lz[node * 2 + 1] = min(lz[node * 2 + 1], lz[node]);
        lz[node] = DEFAULT;
    }
    void set(int node, int s, int e, int idx, T val) {
        if (s == e) {
            tree[node] = val;
            return;
        }
        if (lz[node]) push(node);
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
            tree[node] = min(tree[node], val);
            lz[node] = min(lz[node], val);
            return;
        }
        if (lz[node]) push(node);
        int m = (s + e) / 2;
        update(node * 2, s, m, l, r, val);
        update(node * 2 + 1, m + 1, e, l, r, val);
        tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
    }
    T query(int node, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tree[node];
        if (lz[node]) push(node);
        int m = (s + e) / 2;
        ll left = query(node * 2, s, m, l, r);
        ll right = query(node * 2 + 1, m + 1, e, l, r);
        return std::min(left, right);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    MinSegTree<ll> st(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        st.set(1, 1, N, i, a[i]);
    }
    cin >> Q;
    while (Q--) {
        char c; cin >> c;
        cout << "c: " << c << endl;
        if (c=='m') {
            int l, r; cin >> l >> r;
            cout << "l: " << l << " r: " << r << endl;
            cout << st.query(1, 1, N, l, r) << endl;
        } else {
            ll l, r, x; cin >> l >> r >> x;
            cout << "l: " << l << " r: " << r << " x: " << x << endl;
            st.update(1, 1, N, l, r, x);
            cout << "done" << endl;
        }
    }
    return 0;
}