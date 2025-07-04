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
ll tree[400005], lz[400005];
ll a[100005];

void push(int node) {
    lz[2*node] += lz[node]; lz[2*node+1] += lz[node];
    tree[2*node] += lz[node]; tree[2*node+1] += lz[node];
    lz[node] = 0;
}

//segment tree with range addition and range max
void update(int node, int start, int end, int l, int r, ll val) {
    if (start > r || end < l) return;
    if (start >= l && end <= r) {
        tree[node] += val;
        lz[node] += val;
        return;
    }
    if (lz[node]) push(node);
    int mid = (start + end) / 2;
    update(node*2, start, mid, l, r, val);
    update(node*2+1, mid+1, end, l, r, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

ll query(int node, int start, int end, int qs, int qe) {
    if (start > qe || end < qs) return LLONG_MAX;
    if (start >= qs && end <= qe) return tree[node];
    if (lz[node]) push(node);
    int mid = (start + end) / 2;
    ll lres = query(node*2, start, mid, qs, qe);
    ll rres = query(node*2+1, mid+1, end, qs, qe);
    return min(lres, rres);
}

void build(int node, int start, int end) {
    if (start > end) return;
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    build(1, 1, N);
    while (Q--) {
        char c; cin >> c;
        if (c=='q') {
            int l, r; cin >> l >> r;
            cout << query(1, 1, N, l, r) << endl;
        } else {
            ll l, r, x; cin >> l >> r >> x;
            update(1, 1, N, l, r, x);
        }
    }
    return 0;
}