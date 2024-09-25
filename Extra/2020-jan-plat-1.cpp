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

template<ll MO> struct Mint {
    static const ll mod = MO;
    ll v; explicit operator int() const { return v; } Mint() { v = 0; }
    Mint(ll _v) { v = (-MO < _v && _v < MO) ? _v : _v % MO;
        if (v < 0) v += MO; }
    friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
    friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
    Mint& operator+=(const Mint& m) { if ((v += m.v) >= MO) v -= MO; return *this; }
    Mint& operator-=(const Mint& m) { if ((v -= m.v) < 0) v += MO; return *this; }
    Mint& operator*=(const Mint& m) { v = v*m.v%MO; return *this; }
    Mint& operator/=(const Mint& m) { return (*this) *= inv(m); }
    friend Mint pow(Mint a, ll p) {
        Mint ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend Mint inv(const Mint& a) { return pow(a, MO-2); }
    Mint operator-() const { return Mint(-v); }
    Mint operator++() const { return Mint(v+1); }
    Mint operator--() const { return Mint(v-1); }
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
};

using mint = Mint<MOD>;

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

int N, M;
char a[1005][1005];
int b[1005][1005];
ll dp[1000005];
bool top[1000005];
set<int> adj[1000005];

bool good(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && a[x][y] == '.';
}

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

void solve(int x) {
    dp[x] = 1;
    for (int i : adj[x]) {
        dp[x] = mul(dp[x], dp[i]);
        top[i] = 0;
    }
    dp[x] = add(dp[x], 1);
    top[x] = 1;
}

int main() {
    // freopen("cave.in", "r", stdin);
    // freopen("cave.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    DSU dsu(N*M);
    set<int> s;
    map<int,int> mp;
    for (int i = N-1; i >= 0; i--) {
        s.clear();
        mp.clear();
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '.') {
                if (good(i+1, j)) dsu.unite(i*M+j, (i+1)*M+j);
                if (good(i, j+1)) dsu.unite(i*M+j, i*M+j+1);
            }
        }
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '.') {
                int x = dsu.get(i*M+j);
                if (mp.find(x) == mp.end()) {
                    mp[x] = i*M+j;  
                }
                b[i][j] = mp[x];
            }
        }
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '.') {
                if (good(i+1, j)) adj[b[i][j]].insert(b[i+1][j]);
            }
        }
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '.') {
                if (s.find(b[i][j]) == s.end()) {
                    s.insert(b[i][j]);
                    solve(b[i][j]);
                }
            }
        }
    }
    s.clear();
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '.') {
                if (s.find(b[i][j]) == s.end() && top[b[i][j]]) {
                    s.insert(b[i][j]);
                    ans = mul(ans, dp[b[i][j]]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}