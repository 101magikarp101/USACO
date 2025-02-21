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
int kv, kh;
vt<vt<char>> a;
vt<vt<int>> pre;
vt<vt<bool>> vis;
DSU dsu(0);

int dx[] = {0,-1,-2,-1,0,1,2,1};
int dy[] = {2,1,0,-1,-2,-1,0,1};

bool in(int i, int j) {
    return i >= 1 && i <= N && j >= 1 && j <= M;
}

int get2(int i, int j, int x, int y) {
    int n = min(i,x), m = min(j,y), p = max(i,x), q = max(j,y);
    return pre[p][q] - pre[n-1][q] - pre[p][m-1] + pre[n-1][m-1];
}

int get(int i, int j, int x, int y) {
    return min(get2(i, j, i, y)+get2(i, y, x, y)-(a[i][y] == '@'), get2(i, j, x, j)+get2(x, j, x, y)-(a[x][j] == '@'));
}

void dfs(DSU &dsu, int i, int j) {
    vis[i][j] = 1;
    rep(k,0,8) {
        int ni = i+dx[k], nj = j+dy[k];
        if (in(ni, nj) && get(i, j, ni, nj) == 0 && !vis[ni][nj]) {
            dsu.unite((i-1)*M+j, (ni-1)*M+nj);
            dfs(dsu, ni, nj);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M >> kv >> kh;
    rep(i,0,8) dx[i] *= kv, dy[i] *= kh;
    a = vt<vt<char>>(N+1, vt<char>(M+1));
    pre = vt<vt<int>>(N+1, vt<int>(M+1,0));
    vis = vt<vt<bool>>(N+1, vt<bool>(M+1,0));
    dsu = DSU(N*M+1);
    rep(i,1,N+1) rep(j,1,M+1) cin >> a[i][j];
    rep(i,1,N+1) rep(j,1,M+1) pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + (a[i][j] == '@');
    rep(i,1,N+1) rep(j,1,M+1) {
        if (a[i][j] == '*' && !vis[i][j]) {
            cout << "visiting: " << i << " " << j << endl;
            dfs(dsu, i, j);
        }
    }
    int Q; cin >> Q;
    set<int> s;
    ll ans = 0;
    rep(i,1,N+1) rep(j,1,M+1) {
        if (a[i][j] == '*') {
            if (s.find(dsu.get((i-1)*M+j)) == s.end()) {
                ll sz = dsu.size((i-1)*M+j);
                s.insert(dsu.get((i-1)*M+j));
                ans += sz*(sz-1);
            }
        }
    }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}