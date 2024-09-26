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

template <class T> class SumSegTree {
  private:
    const T DEFAULT = 0;
    vector<T> tr;
    vector<T> lz;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, DEFAULT), lz(l*4, DEFAULT) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tr[i] = tr[i*2] + tr[i*2+1];
        }
    }
    void push(int n, int s, int m, int e) {
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        tr[2*n] += (ll)(m-s+1)*lz[n];
        tr[2*n+1] += (ll)(e-m)*lz[n];
        lz[n] = DEFAULT;
    }
    void add(int n, int s, int e, int idx, T val) {
        if (s == e) {
            tr[n] += val;
            return;
        }
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n,s,m,e);
        if (idx <= m) {
            add(n*2, s, m, idx, val);
        } else {
            add(n*2+1, m+1, e, idx, val);
        }
        tr[n] = tr[n*2]+tr[n*2+1];
    }
    void range_add(int n, int s, int e, int l, int r, T val) {
        if (s>r || e<l) return;
        if (l<=s && e<=r) {
            tr[n] += (ll)(e-s+1)*val;
            lz[n] += val;
            return;
        }
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n,s,m,e);
        range_add(n*2, s, m, l, r, val);
        range_add(n*2+1, m+1, e, l, r, val);
        tr[n] = tr[n*2]+tr[n*2+1];
    }
    T query(int n, int s, int e, int l, int r) {
        if (s>r || e<l) return DEFAULT;
        if (l<=s && e<=r) return tr[n];
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n,s,m,e);
        ll left = query(n*2, s, m, l, r);
        ll right = query(n*2+1, m+1, e, l, r);
        return left+right;
    }
};

int T, N, Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        SumSegTree<ll> st(N);
        while (Q--) {
            int x; cin >> x;
            if (x==0) {
                int l, r; ll v; cin >> l >> r >> v;
                st.range_add(1,1,N,l,r,v);
            } else {
                int l, r; cin >> l >> r;
                cout << st.query(1,1,N,l,r) << endl;
            }
        }
    }
    return 0;
}