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

struct state {
    int tot, p, s, ma;
};

struct query {
    int idx, i, x;
};

struct segment {
    int l, r, x;
    bool operator<(const segment &a) const {
        return l < a.l;
    }
};

template <class T> class SumSegTree {
  private:
    const state DEFAULT = {0, 0, 0, 0};
    vector<state> tr;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, DEFAULT) {}
    state merge(state a, state b) {
        state res;
        res.tot = a.tot + b.tot;
        res.p = max(a.p, a.tot + b.p);
        res.s = max(b.s, b.tot + a.s);
        res.ma = max({a.ma, b.ma, a.s + b.p});
        return res;
    }
    void set(int n, int s, int e, int idx, T val) {
        if (s == e) {
            tr[n] = val;
            return;
        }
        int m = (s+e)/2;
        if (idx <= m) {
            set(n*2, s, m, idx, val);
        } else {
            set(n*2+1, m+1, e, idx, val);
        }
        tr[n] = merge(tr[n*2], tr[n*2+1]);
    }
    state query(int n, int s, int e, int l, int r) {
        if (s>r || e<l) return DEFAULT;
        if (l<=s && e<=r) return tr[n];
        int m = (s+e)/2;
        state left = query(n*2, s, m, l, r);
        state right = query(n*2+1, m+1, e, l, r);
        return merge(left, right);
    }
};

int T, N, Q;
int a[300005], b[300005];
vt<int> init[300005];
vt<query> qs[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> Q;
        rep(i,1,N+1) {
            init[i].clear();
            qs[i].clear();
        }
        rep(i,0,N) {
            cin >> a[i];
            init[a[i]].pb(i);
            b[i] = a[i];
        }
        rep(i,0,Q) {
            int id, x; cin >> id >> x;
            id--;
            qs[b[id]].pb({i, id, x});
            b[id] = x;
            qs[x].pb({i, id, x});
        }
        SumSegTree<state> tree(N);
        rep(i,0,N) {
            tree.set(1, 0, N-1, i, {-1, -1, -1, -1});
        }
        vt<int> ans(Q, 0);
        mset<segment> segs;
        rep(x,1,N+1) {
            for (int i : init[x]) {
                tree.set(1, 0, N-1, i, {1, 1, 1, 1});
            }
            pii prev = {-1, tree.query(1, 0, N-1, 0, N-1).ma/2};
            each(q,qs[x]) {
                int idx = q.idx;
                int i = q.i;
                int y = q.x;
                if (y == x) {
                    tree.set(1, 0, N-1, i, {1, 1, 1, 1});
                } else {
                    tree.set(1, 0, N-1, i, {-1, -1, -1, -1});
                }
                state res = tree.query(1, 0, N-1, 0, N-1);
                segs.insert({prev.x, idx-1, prev.y});
                prev = {idx, res.ma/2};
            }
            segs.insert({prev.x, Q-1, prev.y});
            rrep(i,sz(qs[x])-1,0) {
                int idx = qs[x][i].i;
                tree.set(1, 0, N-1, idx, {-1, -1, -1, -1});
            }
            each(i,init[x]) {
                tree.set(1, 0, N-1, i, {-1, -1, -1, -1});
            }
        }
        mset<int> vals;
        mset<pii> rs;
        rep(i,0,Q) {
            while (!segs.empty() && segs.begin()->l <= i) {
                segment seg = *segs.begin();
                segs.erase(segs.begin());
                if (seg.r < i) continue; // skip segments that end before i
                vals.insert(seg.x);
                rs.insert({seg.r, seg.x});
            }
            while (!rs.empty() && rs.begin()->x < i) {
                pii p = *rs.begin();
                rs.erase(rs.begin());
                vals.erase(vals.find(p.y));
            }
            if (!vals.empty()) {
                ans[i] = *vals.rbegin();
            }
        }
        rep(i,0,Q) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}