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

template <class T> class SumSegTree {
  public:
    const T DEFAULT = 0;
    vector<pll> tr;
    vector<T> lz;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, {0,1}), lz(l*4, 0) {}
    void print(int n, int s, int e) {
        cout << "n: " << n << " s: " << s << " e: " << e << " tr: " << tr[n].x << " " << tr[n].y << " lz: " << lz[n] << endl;
        if (s == e) return;
        int m = (s+e)/2;
        print(n*2, s, m);
        print(n*2+1, m+1, e);
    }
    pll merge(pll a, pll b) {
        if (a.x < b.x) return a;
        else if (a.x > b.x) return b;
        else return {a.x, a.y+b.y};
    }
    void sety(int n, int s, int e, int i, T val) {
        if (s == e) {
            tr[n] = {0,val};
            return;
        }
        int m = (s+e)/2;
        if (i <= m) sety(n*2, s, m, i, val);
        else sety(n*2+1, m+1, e, i, val);
        tr[n] = merge(tr[n*2], tr[n*2+1]);
    }
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tr[i] = merge(tr[i<<1], tr[i<<1|1]);
        }
    }
    void push(int n) {
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        tr[2*n].x += lz[n];
        tr[2*n+1].x += lz[n];
        lz[n] = 0;
    }
    void range_add(int n, int s, int e, int l, int r, T val) {
        if (s>r || e<l) return;
        if (l<=s && e<=r) {
            tr[n].x += val;
            lz[n] += val;
            return;
        }
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n);
        range_add(n*2, s, m, l, r, val);
        range_add(n*2+1, m+1, e, l, r, val);
        tr[n] = merge(tr[n*2], tr[n*2+1]);
    }
    pll query(int n, int s, int e, int l, int r) {
        if (s>r || e<l) return {INT_MAX,0};
        if (l<=s && e<=r) return tr[n];
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n);
        pll left = query(n*2, s, m, l, r);
        pll right = query(n*2+1, m+1, e, l, r);
        return merge(left, right);
    }
};

const int MAXN = 200005;

ll Q, W;
const double s2 = sqrt(2);
map<ll,ll> cmp;
ll rev[MAXN*2];
pll q[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    cin >> Q >> W;
    cout << fixed << setprecision(10);
    set<ll> s;
    ll mi = W, ma = 0;
    rep(i,0,Q) {
        cin >> q[i].x >> q[i].y;
        ll l = max(0LL, q[i].x-q[i].y), r = min(W, q[i].x+q[i].y);
        ckmin(mi, l);
        ckmax(ma, r);
        s.insert(l);
        s.insert(r);
    }
    int cnt = 0;
    for (ll i : s) {
        cmp[i] = cnt;
        rev[cnt] = i;
        // cout << "cmp[" << i << "]: " << cmp[i] << endl;
        cnt++;
    }
    // cout << "cnt: " << cnt << endl;
    SumSegTree<ll> st(cnt-1);
    rep(i,0,cnt-1) {
        st.sety(1,0,cnt-2,i,rev[i+1]-rev[i]);
    }
    // st.build();
    // st.print(1,0,cnt-2);
    mset<pll> pts;
    rep(qq,0,Q) {
        ll x = q[qq].x, y = q[qq].y;
        pll p = {x,y};
        ll l = max(0LL, x-y), r = min(W, x+y);
        // cout << "l: " << l << " r: " << r << endl;
        // cout << "cmp[l]: " << cmp[l] << " cmp[r]: " << cmp[r] << endl;
        if (pts.count(p)) {
            pts.erase(pts.find(p));
            st.range_add(1,0,cnt-2,cmp[l],cmp[r]-1,-1);
        } else {
            pts.insert(p);
            st.range_add(1,0,cnt-2,cmp[l],cmp[r]-1,1);
        }
        pll res = st.query(1,0,cnt-2,0,cnt-2);
        // cout << "res.x: " << res.x << " res.y: " << res.y << endl;
        // rep(i,1,cnt*2) {
        //     cout << "i: " << i << " tr.x: " << st.tr[i].x << " tr.y: " << st.tr[i].y << " lz: " << st.lz[i] << endl;
        // }
        double ans = ma-mi;
        if (res.x == 0) ans -= res.y;
        ans *= s2;
        cout << ans << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cerr << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}