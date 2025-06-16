#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
template <class T> using vvt = vt<vt<T>>;
template <class T> using vvvt = vt<vvt<T>>;
template <class T> using vvvvt = vt<vvvt<T>>;
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

int dist(pii &a, pii &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct edge {
    int u, v, w;
    bool operator<(const edge &a) const { return w > a.w; }
};

struct DSU {
    vt<pii> loc;
    priority_queue<edge> pq;
    vector<int> e;
    DSU(vt<pii> &a) {
        loc = a;
        e.resize(sz(a), -1);
        rep(i,0,sz(a)) {
            rep(j,i+1,sz(a)) {
                int d = dist(a[i], a[j]);
                pq.push({i, j, d});
            }
        }
    }

    void add(pii p) {
        int n = sz(e);
        rep(i,0,n) {
            int d = dist(p, loc[i]);
            pq.push({n, i, d});
        }
        loc.pb(p);
        e.pb(-1);
    }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    int query() {
        int mi = INT_MAX;
        while (!pq.empty()) {
            edge cur = pq.top();
            if (same_set(cur.u, cur.v)) {
                pq.pop();
                continue;
            }
            if (cur.w > mi) break;
            unite(cur.u, cur.v);
            pq.pop();
            mi = cur.w;
        }
        return mi==INT_MAX ? -1 : mi;
    }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int N, Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    vt<pii> a(N);
    rep(i,0,N) cin >> a[i].x >> a[i].y;
    DSU dsu(a);
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            dsu.add({x, y});
        } else if (t == 2) {
            cout << dsu.query() << endl;
        } else {
            int x, y; cin >> x >> y;
            x--; y--;
            cout << (dsu.same_set(x, y) ? "Yes" : "No") << endl;
        }
        // dsu.print();
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}