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

ll N;
ll a[1000005];
ll sufmin[1000005], premax[1000005];
ll suf[1000005], pre[1000005];

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
    T query(int n, int s, int e, int l, int r) {
        if (l>r) return DEFAULT;
        if (s>r || e<l) return DEFAULT;
        if (l<=s && e<=r) return tr[n];
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n,s,m,e);
        ll left = query(n*2, s, m, l, r);
        ll right = query(n*2+1, m+1, e, l, r);
        return left+right;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    set<int> s;
    map<int,int> m;
    rep(i,0,N) {
        cin >> a[i];
        s.insert(a[i]);
    }
    each(i,s) {
        m[i] = sz(m);
    }
    rep(i,0,N) {
        a[i] = m[a[i]];
    }
    sufmin[N] = INT_MAX;
    for (int i = N-1; i >= 0; i--) {
        sufmin[i] = min(sufmin[i+1],a[i]);
    }
    premax[0] = a[0];
    for (int i = 1; i < N; i++) {
        premax[i] = max(premax[i-1],a[i]);
    }
    suf[N] = 0;
    for (int i = N-1; i >= 0; i--) {
        if (sufmin[i] == a[i]) {
            suf[i] = suf[i+1];
        } else {
            suf[i] = N-i;
        }
    }
    pre[0] = 0;
    for (int i = 1; i < N; i++) {
        if (premax[i] == a[i]) {
            pre[i] = pre[i-1];
        } else {
            pre[i] = i+1;
        }
    }
    ll ans = min(pre[N-1]*pre[N-1],suf[0]*suf[0]);
    SumSegTree<ll> st(N);
    rep(i,0,N) {
        st.add(1,0,N-1,a[i],1);
        ll cur = (ll)(i+1)*(i+1);
        if (i < N-1) {
            ll res = st.query(1,0,N-1,0,sufmin[i+1]);
            if (res == i+1) {
                cur += suf[i+1]*suf[i+1];
            } else {
                cur += (N-res)*(N-res);
            }  
        }
        // cout << "i: " << i << " cur: " << cur << endl;
        ckmin(ans,cur);
    }
    SumSegTree<ll> st2(N);
    for (int i = N-1; i >= 0; i--) {
        st2.add(1,0,N-1,a[i],1);
        ll cur = (ll)(N-i)*(N-i);
        if (i > 0) {
            ll res = st2.query(1,0,N-1,0,premax[i-1]-1);
            if (res == 0) {
                cur += pre[i-1]*pre[i-1];
            } else {
                cur += (res+i)*(res+i);
            }
            // cur += (res+i)*(res+i);
        }
        // cout << "i: " << i << " cur: " << cur << endl;
        ckmin(ans,cur);
    }
    cout << ans << endl;
    return 0;
}