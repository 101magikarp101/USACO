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
    if (b <= 0) return 1;
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

template <class T> class SumSegTree {
  private:
    const T DEFAULT = 0;
    vector<T> tr;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, DEFAULT) {}
    void add(int n, int s, int e, int idx, T val) {
        if (s == e) {
            tr[n] = (tr[n]+val)%MOD;
            return;
        }
        int m = (s+e)/2;
        if (idx <= m) {
            add(n*2, s, m, idx, val);
        } else {
            add(n*2+1, m+1, e, idx, val);
        }
        tr[n] = (tr[n*2]+tr[n*2+1])%MOD;
    }
    void set (int n, int s, int e, int idx, T val) {
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
        tr[n] = (tr[n*2]+tr[n*2+1])%MOD;
    }
    T query(int n, int s, int e, int l, int r) {
        if (s>r || e<l) return DEFAULT;
        if (l<=s && e<=r) return tr[n];
        int m = (s+e)/2;
        int left = query(n*2, s, m, l, r);
        int right = query(n*2+1, m+1, e, l, r);
        return (left+right)%MOD;
    }
};

int T, N;
bool a[200005];

int query(SumSegTree<int> &zst, SumSegTree<int> &ost, int x) {
    int res = 0;
    if (a[x]) {
        res = zst.query(1,0,N-1,0,x-1);
    } else {
        res = ost.query(1,0,N-1,0,x-1);
    }
    res = ad(res, 1);
    res = mul(res, binpow(2,(N-1)-x));
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        string s; cin >> s;
        N = sz(s);
        SumSegTree<int> zst(N), ost(N);
        SumSegTree<int> zstsuf(N), ostsuf(N);
        rep(i,0,N) {
            a[i] = s[i]-'0';
        }
        int ans = 0;
        rep(i,0,N) {
            if (!a[i]) {
                zst.add(1,0,N-1,i,binpow(2,i));
                zstsuf.add(1,0,N-1,i,binpow(2,(N-1)-i));
            } else {
                ost.add(1,0,N-1,i,binpow(2,i));
                ostsuf.add(1,0,N-1,i,binpow(2,(N-1)-i));
            }
        }
        rep(i,0,N) {
            ans = ad(ans, query(zst, ost, i));
            // cout << "ans: " << ans << ' ';
        }
        // cout << "ans: " << ans << endl;
        int Q; cin >> Q;
        while (Q--) {
            int x; cin >> x;
            x--;
            ans = sub(ans, query(zst, ost, x));
            if (a[x]) {
                ost.set(1,0,N-1,x,0);
                ostsuf.set(1,0,N-1,x,0);
                zst.add(1,0,N-1,x,binpow(2,x));
                zstsuf.add(1,0,N-1,x,binpow(2,(N-1)-x));

                ans = sub(ans, mul(binpow(2,x), zstsuf.query(1,0,N-1,x+1,N-1)));
                ans = ad(ans, mul(binpow(2,x), ostsuf.query(1,0,N-1,x+1,N-1)));
            }
            else {
                zst.set(1,0,N-1,x,0);
                zstsuf.set(1,0,N-1,x,0);
                ost.add(1,0,N-1,x,binpow(2,x));
                ostsuf.add(1,0,N-1,x,binpow(2,(N-1)-x));

                ans = sub(ans, mul(binpow(2,x), ostsuf.query(1,0,N-1,x+1,N-1)));
                ans = ad(ans, mul(binpow(2,x), zstsuf.query(1,0,N-1,x+1,N-1)));
            }
            a[x] = !a[x];
            ans = ad(ans, query(zst, ost, x));
            cout << ans << ' ';
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}