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

int N, X;
int a[100005];

int ad(int a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD2;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD2);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD2-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

template <class T> class SumSegTree {
  private:
    const T DEFAULT = 0;
    vector<T> tr;
    vector<T> lz;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, DEFAULT), lz(l*4, DEFAULT) {}
    void push(int n, int s, int m, int e) {
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        tr[2*n] += (ll)(m-s+1)*lz[n];
        tr[2*n+1] += (ll)(e-m)*lz[n];
        lz[n] = DEFAULT;
    }
    void add(int n, int s, int e, int idx, T val) {
        if (s == e) {
            tr[n] = ad(tr[n], val);
            return;
        }
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n,s,m,e);
        if (idx <= m) {
            add(n*2, s, m, idx, val);
        } else {
            add(n*2+1, m+1, e, idx, val);
        }
        tr[n] = ad(tr[n*2], tr[n*2+1]);
    }
    T query(int n, int s, int e, int l, int r) {
        if (s>r || e<l) return DEFAULT;
        if (l<=s && e<=r) return tr[n];
        int m = (s+e)/2;
        if (lz[n] != DEFAULT) push(n,s,m,e);
        int left = query(n*2, s, m, l, r);
        int right = query(n*2+1, m+1, e, l, r);
        return ad(left, right);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> X;
    rep(i,0,N) cin >> a[i];
    SumSegTree<int> st(100005);
    SumSegTree<int> cnt(100005);
    int ans = 0;
    rep(i,0,N) {
        int l = max(0, a[i]-X);
        int r = min(100000, a[i]+X);
        int val = st.query(1,0,100000,l,r);
        val = sub(val, st.query(1,0,100000,a[i],a[i]));
        // cout << "val: " << val << endl;
        int c = cnt.query(1,0,100000,l,r);
        c = sub(c, cnt.query(1,0,100000,a[i],a[i]));
        c = ad(c,1);
        val = ad(val, mul(c, a[i]));
        // cout << "val: " << val << endl;
        // cout << "c: " << c << endl;
        ans = ad(ans, val);
        // cout << "ans: " << ans << endl;
        st.add(1,0,100000,a[i],val);
        cnt.add(1,0,100000,a[i],c);
    }
    cout << ans << endl;
    return 0;
}