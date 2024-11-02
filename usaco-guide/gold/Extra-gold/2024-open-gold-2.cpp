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
#define fi first
#define se second
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

struct seg {
    ll l, r, k;
    int i;
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

int N;
seg a[200005];
int ans[200005];
map<int,int> mp, rev;
map<int,vt<seg>> m;
seg b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        cin >> a[i].l >> a[i].r >> a[i].k;
        s.insert(a[i].l);
        s.insert(a[i].r);
        a[i].i = i;
        m[a[i].k].pb(a[i]);
        b[i] = a[i];
    }
    sort(b, b+N, [](seg a, seg b) {
        return a.r-a.l < b.r-b.l;
    });
    int cnt = 0;
    for (auto &i : s) {
        mp[i] = cnt;
        rev[cnt] = i;
        cnt++;
    }
    SumSegTree<ll> str(s.size()), stl(s.size()), st(s.size());
    int n = s.size();
    for (int i = 0; i < N; i++) {
        seg &s = a[i];
        str.add(1, 0, n-1, mp[s.r], 1);
        stl.add(1, 0, n-1, mp[s.l], 1);
        cout << "added: l: " << mp[s.l] << " r: " << mp[s.r] << endl;
    }
    for (int i = 0; i < N; i++) {
        int l = mp[a[i].l], r = mp[a[i].r];
        auto itr = --upper_bound(all(s), a[i].r-a[i].k);
        int r2 = mp[*itr];
        auto itl = lower_bound(all(s), a[i].l+a[i].k);
        int l2 = mp[*itl];
        cout << "l: " << l << " r: " << r << endl;
        cout << "l2: " << l2 << " r2: " << r2 << endl;
        int ii = a[i].i;
        ans[ii] = str.query(1, 0, n-1, l2, r)+stl.query(1, 0, n-1, l, r2)-2;
        cout << "ii: " << ii << " ans: " << ans[ii] << endl;
    }
    cout << endl;
    int cur = -1;
    for (auto &x : m) {
        // for (auto &s : x.se) {
        //     st.add(1, 0, n-1, mp[s.l], 1);
        // }
        while (cur < N-1 && b[cur+1].r-b[cur+1].l < x.fi) {
            cur++;
            st.add(1, 0, n-1, mp[b[cur].l], 1);
            cout << "added: " << mp[b[cur].l] << endl;
        }
        for (auto &ss : x.se) {
            int l = mp[ss.l], r = mp[ss.r];
            auto itr = --upper_bound(all(s), ss.r-ss.k);
            int r2 = mp[*itr];
            cout << "l: " << l << " r: " << r << endl;
            cout << "r2: " << r2 << endl;
            int ii = ss.i;
            ans[ii] -= st.query(1, 0, n-1, l, r2)+stl.query(1, 0, n-1, l, r2)-1;
            cout << "ii: " << ii << " ans: " << ans[ii] << endl;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}