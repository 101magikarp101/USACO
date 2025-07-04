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
    return a>=MOD2 ? a-MOD2 : a;
}

void adi(int &a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
}

int sub(int a, int b) {
    a-=b;
    return a<0 ? a+MOD2 : a;
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

struct mat {
    vt<vt<int>> a;
    mat(int n, int m) : a(n, vt<int>(m)) {}
    mat operator*(const mat &b) {
        mat c(sz(a), sz(b.a[0]));
        rep(i,0,sz(a)) {
            rep(j,0,sz(b.a[0])) {
                rep(k,0,sz(b.a)) {
                    c.a[i][j] = ad(c.a[i][j], mul(a[i][k], b.a[k][j]));
                }
            }
        }
        return c;
    }
};

mat binpow(mat a, int b) {
    mat res(sz(a.a), sz(a.a));
    rep(i,0,sz(a.a)) res.a[i][i] = 1;
    while (b) {
        if (b&1) res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

struct edge {
    int v, t;
};

int N, M, K;
vt<edge> adj[55];
int invi[100005];

// O((5N)^3 * log K)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    rep(i,0,100005) invi[i] = inv(i);

    cin >> N >> M >> K;
    rep(i,0,M) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        adj[u].pb({v, t});
        adj[v].pb({u, t});
    }
    mat dp(N*5, N*5);
    rep(i,0,N) {
        each(j,adj[i]) {
            if (j.t != 1 || j.v != N-1) adi(dp.a[i*5][j.v*5+j.t-1], invi[sz(adj[i])]);
        }
        rep(j,1,5) {
            if (i == N-1 && j == 1) dp.a[i*5+j][i*5+j-1] = 0;
            else dp.a[i*5+j][i*5+j-1] = 1;
        }
        if (sz(adj[i]) == 0) {
            dp.a[i*5][i*5] = 1;
        }
    }
    dp = binpow(dp, K);
    int ans = 0;
    rep(i,0,N*5) ans = ad(ans, dp.a[0][i]);
    ans = sub(1, ans);
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}