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

int N, M, K;
ll INF = 1LL<<60;

struct mat {
    vt<vt<ll>> a;
    mat(int n, int m) {
        a = vt<vt<ll>>(n, vt<ll>(m, INF));
    }
    mat operator*(const mat &b) {
        mat c(sz(a), sz(b.a[0]));
        for (int i = 0; i < sz(a); i++) {
            for (int j = 0; j < sz(b.a[0]); j++) {
                for (int k = 0; k < sz(b.a); k++) {
                    c.a[i][j] = min(c.a[i][j], a[i][k]+b.a[k][j]);
                }
            }
        }
        return c;
    }
};

mat binpow(mat a, int b) {
    b--;
    mat res = a;
    while (b) {
        if (b&1) res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    mat m(N, N);
    for (int i = 0; i < M; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        u--; v--;
        m.a[u][v] = min(m.a[u][v], w);
    }
    m = binpow(m, K);
    cout << (m.a[0][N-1] == INF ? -1 : m.a[0][N-1]) << endl;
    return 0;
}