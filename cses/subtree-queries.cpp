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

int N, Q;
int a[200005];
pii ord[200005];
vt<int> adj[200005];
int t = 0;

void dfs(int u, int p) {
    ord[u].x = t++;
    for (int v : adj[u]) {
        if (v==p) continue;
        dfs(u, p);
    }
    ord[u].y = t++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    template <class T> class SumSegTree {
        //MUST BE 0-INDEXED
      private:
        const T DEFAULT = 0;
        vector<T> segtree;
        int len;
      public:
        SumSegTree(int l) : len(l), segtree(l * 4, DEFAULT) {}
        void build() {
            for (int i = len - 1; i > 0; i--) {
                segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
            }
        }
        //set the value at index ind to val
        void set(int ind, T val) {
            ind += len;
            segtree[ind] = val;
            for (; ind > 1; ind /= 2) {
                segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
            }
        }
        //add val to the value at index ind
        void add(int ind, T val) {
            ind += len;
            segtree[ind] += val;
            for (; ind > 1; ind /= 2) {
                segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
            }
        }
        //add val to all elements in the range [l, r]
        //v: index of current node
        //tl: left bound of current node
        //tr: right bound of current node
        //l: left bound of range to update
        //r: right bound of range to update
        //add: value to add to all elements in the range [l, r]
        void update(int v, int tl, int tr, int l, int r, T add) {
            if (l > r) return;
            if (l == tl && tr == r) {
                segtree[v] += add;
            } else {
                int tm = (tl + tr) / 2;
                update(v * 2, tl, tm, l, min(r, tm), add);
                update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
            }
        }
        //get the value at index pos 
        //v: index of current node
        //tl: left bound of current node
        //tr: right bound of current node
        //pos: index of element to get
        T get(int v, int tl, int tr, int pos) {
            if (tl == tr) {
                return segtree[v];
            }
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                return segtree[v] + get(v * 2, tl, tm, pos);
            } else {
                return segtree[v] + get(v * 2 + 1, tm + 1, tr, pos);
            }
        }
        /** @return the sum of the elements in the range [start, end) */
        T range_sum(int start, int end) {
            T sum = DEFAULT;
            for (start += len, end += len; start < end; start /= 2, end /= 2) {
                if (start % 2 == 1) { sum += segtree[start++]; }
                if (end % 2 == 1) { sum += segtree[--end]; }
            }
            return sum;
        }
    };
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    return 0;
}