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

int T, N, D;
bool a[1005][1005];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool in(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

struct DSU {
    vector<int> e;
    vt<set<int>> conn;
    vt<vt<int>> adj;
    double tot = 0;
    multiset<pii> s;
    int cnt = 0;
    DSU(int N) {
        e = vector<int>(N, 0);
        conn = vt<set<int>>(N);
        adj = vt<vt<int>>(N);
        rep(i,0,N) s.insert({0, 0});
    }

    // get representive component (uses path compression)
    pii get(int x) {
        if (e[x] <= 0) return {x, sz(conn[x])};
        auto p = get(e[x]);
        e[x] = p.x;
        return p;
    }

    void print() {
        cout << "s:" << endl;
        for (auto x : s) cout << "{" << x.x << ", " << x.y << "}, ";
        cout << endl;
    }

    bool same_set(int a, int b) { return get(a).x == get(b).x; }

    int size(int x) { return -e[get(x).x]; }

    void add(int x, int y) {
        if (a[x][y]) return;
        a[x][y] = 1;

        pii z = get((x-1)*N+y);
        s.erase(s.find({-e[z.x], z.y}));
        e[z.x]--;
        tot += max(0.0, -e[z.x]-sqrt(z.y));
        s.insert({-e[z.x], z.y});
        
        set<int> vis;
        rep(d,0,4) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (in(nx, ny) && a[nx][ny]) {
                pii p = get((nx-1)*N+ny);
                if (vis.count(p.x)) continue;
                vis.insert(p.x);
                unite(z.x, (nx-1)*N+ny);
            }
        }
        each(x, adj[(x-1)*N+y]) {
            int xx = x/N+1;
            int yy = x%N;
            if (!a[xx][yy] || vis.count(x)) continue;
            vis.insert(x);
            unite(z.x, x);
        }
    }

    void connect(int x1, int y1, int x2, int y2) {
        cnt++;
        int z1 = (x1-1)*N+y1;
        int z2 = (x2-1)*N+y2;
        pii p1 = get(z1);
        pii p2 = get(z2);
        if (p1 == p2) {
            tot -= max(0.0, -e[p1.x]-sqrt(p1.y));
            s.erase(s.find({-e[p1.x], p1.y}));
            conn[p1.x].insert(cnt);
            p1.y = sz(conn[p1.x]);
            tot += max(0.0, -e[p1.x]-sqrt(p1.y));
            s.insert({-e[p1.x], p1.y});
            return;
        }
        tot -= max(0.0, -e[p1.x]-sqrt(p1.y));
        tot -= max(0.0, -e[p2.x]-sqrt(p2.y));
        s.erase(s.find({-e[p1.x], p1.y}));
        s.erase(s.find({-e[p2.x], p2.y}));

        conn[p1.x].insert(cnt);
        conn[p2.x].insert(cnt);
        s.insert({-e[p1.x], sz(conn[p1.x])});
        s.insert({-e[p2.x], sz(conn[p2.x])});
        tot += max(0.0, -e[p1.x]-sqrt(sz(conn[p1.x])));
        tot += max(0.0, -e[p2.x]-sqrt(sz(conn[p2.x])));
        if (a[x1][y1] && a[x2][y2]) unite(z1, z2);
        else {
            adj[z1].pb(z2);
            adj[z2].pb(z1);
        }
    }

    bool unite(int x, int y) {  // union by size
        pii p1 = get(x);
        pii p2 = get(y);
        if (p1 == p2) return false;
        if (sz(conn[p1.x]) < sz(conn[p2.x])) swap(p1, p2);

        tot -= max(0.0, -e[p1.x]-sqrt(p1.y));
        tot -= max(0.0, -e[p2.x]-sqrt(p2.y));
        s.erase(s.find({-e[p1.x], p1.y}));
        s.erase(s.find({-e[p2.x], p2.y}));

        e[p1.x] += e[p2.x];
        e[p2.x] = p1.x;
        conn[p1.x].insert(all(conn[p2.x]));
        conn[p2.x].clear();
        p1.y = sz(conn[p1.x]);
        tot += max(0.0, -e[p1.x]-sqrt(p1.y));
        s.insert({-e[p1.x], p1.y});

        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> D;
    DSU dsu(N*N+1);
    rep(i,1,N+1) {
        string s;
        cin >> s;
        rep(j,1,N+1) {
            if (s[j-1]-'0') dsu.add(i, j);
        }
    }
    while (D--) {
        int k; cin >> k;
        if (k == 1) {
            int x, y; cin >> x >> y;
            dsu.add(x+1, y+1);
        } else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            dsu.connect(x1+1, y1+1, x2+1, y2+1);
        }
        // dsu.print();
        cout << fixed << setprecision(10) << dsu.tot << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}