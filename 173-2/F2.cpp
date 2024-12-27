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

int T, N, Q;
int a[100005];

int ad(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD);
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
    return binpow(a, MOD-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

pii merge(pii a, pii b) {
    if (a.y == b.y) return {ad(a.x, b.x), a.y};
    if (a.y < b.y) return a;
    return b;
}

pii merge1(pii a, pii b) {
    return {mul(a.x, b.x), min((int)1e9, a.y+b.y)};
}

struct dat {
    vt<pii> v;
    dat() {
        v = vt<pii>(64,{0,(int)1e9});
    }
    dat(int x) {
        v = vt<pii>(64,{0,(int)1e9});
        v[x] = {1,1};
    }
    dat operator+(const dat &a) const {
        dat res;
        rep(i,0,64) {
            rep(j,0,64) {
                int k = i^j;
                res.v[k] = merge(res.v[k], merge1(v[i], a.v[j]));
            }
        }
        rep(i,0,64) {
            res.v[i] = merge(res.v[i], a.v[i]);
        }
        rep(i,0,64) {
            res.v[i] = merge(res.v[i], v[i]);
        }
        return res;
    }
};

template <class T> class SumSegTree {
  private:
    const pii DEFAULT = {0,(int)1e9};
    const dat D = dat();
    vector<dat> tr;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4) {}
    void print() {
        rep(i,1,4*len) {
            cout << "(" << tr[i].v[0].x << "," << tr[i].v[0].y << ") ";
        }
        cout << endl;
    }
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tr[i] = tr[i*2] + tr[i*2+1];
        }
    }
    void set(int idx, int val) {
        tr[len+idx].v[a[idx]] = {1,1};
    }
    void set(int n, int s, int e, int idx, int val) {
        if (s == e) {
            tr[n].v[a[idx]] = {1,1};
            return;
        }
        int m = (s+e)/2;
        if (idx <= m) {
            set(n*2, s, m, idx, val);
        } else {
            set(n*2+1, m+1, e, idx, val);
        }
        tr[n] = tr[n*2]+tr[n*2+1];
    }
    dat query(int n, int s, int e, int l, int r) {
        // cout << "s: " << s << " e: " << e << " l: " << l << " r: " << r << endl;
        if (s>r || e<l) return D;
        if (l<=s && e<=r) return tr[n];
        int m = (s+e)/2;
        dat left = query(n*2, s, m, l, r);
        dat right = query(n*2+1, m+1, e, l, r);
        dat res = left+right;
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    cin >> N >> Q;
    rep(i,1,N+1) {
        cin >> a[i];
    }
    SumSegTree<int> st(N+1);
    rep(i,1,N+1) {
        // st.set(1,1,N+1,i,a[i]);
        st.set(i,a[i]);
    }
    st.build();
    auto mid = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(mid-start);
    cerr << "Time: " << dur.count() << "ms" << endl;
    // st.print();
    while (Q--) {
        int l, r; cin >> l >> r;
        pii res = st.query(1,1,N+1,l,r).v[0];
        if (res.y == (int)1e9) {
            cout << -1 << endl;
        } else {
            cout << r-l+1-res.y << " " << res.x << endl;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
    cerr << "Time: " << duration.count() << "ms" << endl;
    return 0;
}