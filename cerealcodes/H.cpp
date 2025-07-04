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

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

int N, M, K, Q;
int a[3005];
pii dis[2000005];
bool b[3005][3005];
DSU dsu(3005);
vt<ll> v;

ll solve(int m) {
    ll res = 1;
    for (int i = 0; i < sz(v); i++) {
        ll cnt = 0;
        for (int j = 0; j <= m; j++) {
            if (b[v[i]][j]) {
                cnt++;
            }
        }
        res = mul(res, cnt);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            b[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        x--;
        dis[i] = {x, y};
    }
    for (int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        while (x<y) {
            dsu.unite(x, y);
            x++; y--;
        }
    }
    for (int i = 0; i < N; i++) {
        if (a[i] != -1) {
            int t = dsu.get(i);
            for (int j = 0; j <= M; j++) {
                if (j!=a[i]) {
                    b[t][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < K; i++) {
        int x = dis[i].x, y = dis[i].y;
        if (y > M) continue;
        int t = dsu.get(x);
        b[t][y] = 0;
    }
    for (int i = 0; i < N; i++) {
        if (dsu.get(i) == i) {
            v.pb(i);
        }
    }
    ll ans = solve(M);
    cout << ans << endl;
    return 0;
}