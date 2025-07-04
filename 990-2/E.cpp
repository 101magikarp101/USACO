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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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
  private:
    const T DEFAULT = 0;
    vector<T> tr;
    vector<T> lz;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, DEFAULT), lz(l*4, DEFAULT) {}
    int find(int n, int s, int e, T val) {
        if (s == e) return s;
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n,s,m,e);
        if (tr[n*2] >= val) return find(n*2, s, m, val);
        return find(n*2+1, m+1, e, val-tr[n*2]);
    }
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

int T, N;
pii a[100005];
map<int,int> comp;
int rev[100005];
int totl = 0, totr = 0;

int solve(SumSegTree<int> &stl, SumSegTree<int> &str, int x) {
    int l1 = stl.find(1,0,sz(comp)-1,x);
    int r1 = x!=0?stl.find(1,0,sz(comp)-1,totl-x+1):sz(comp);
    int l2 = str.find(1,0,sz(comp)-1,x);
    int r2 = x!=0?str.find(1,0,sz(comp)-1,totr-x+1):sz(comp);
    // cout << "x: " << x << endl;
    // cout << "l1: " << l1 << " r1: " << r1 << " l2: " << l2 << " r2: " << r2 << endl;
    l1 = rev[l1];
    r1 = rev[r1];
    l2 = rev[l2];
    r2 = rev[r2];
    l1++;
    l2++;
    int l = max(l1,l2);
    int r = min(r1,r2);
    if (r>=l) {
        return r;
    } else {
        return INT_MAX;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        totl = 0;
        totr = 0;
        comp.clear();
        cin >> N;
        map<int,vt<int>> m;
        set<int> s;
        rep(i,0,N) {
            cin >> a[i].x >> a[i].y;
            s.insert(a[i].y);
        }
        int cnt = 0;
        each(i,s) {
            comp[i] = cnt;
            rev[cnt] = i;
            cnt++;
        }
        rep(i,0,N) {
            m[a[i].x].pb(comp[a[i].y]);
        }
        SumSegTree<int> stl(cnt), str(cnt);
        int ans = 0;
        pii p = {(int)-1e9,(int)-1e9};
        rep(i,0,N) {
            int y = comp[a[i].y];
            str.add(1,0,cnt-1,y,1);
            totr++;
        }
        each(x,m) {
            int l = 0, r = N;
            while (l < r) {
                int m = (l+r+1)/2;
                if (solve(stl,str,m)!=INT_MAX) l = m;
                else r = m-1;
            }
            int y = solve(stl,str,l);
            // cout << "l: " << l << " y: " << y << endl;
            if (l > ans && y != INT_MAX) {
                ans = l;
                p = {x.fi,y};
            }
            vt<int> &v = x.se;
            each(i,v) {
                // cout << "i: " << i << endl;
                str.add(1,0,cnt-1,i,-1);
                stl.add(1,0,cnt-1,i,1);
                totr--;
                totl++;
            }
        }
        cout << ans << endl;
        cout << p.x << " " << p.y << endl;
    }
    return 0;
}