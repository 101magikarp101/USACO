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

int N, M;

struct DSU {
    vector<int> e;
    vt<int> xmin, xmax, ymin, ymax;
    multiset<int> rects; // areas of all rectangles
    DSU(int N, vt<pii> &v) : e(N, -1), xmin(N), xmax(N), ymin(N), ymax(N) {
        for (int i = 0; i < N; i++) {
            xmin[i] = xmax[i] = v[i].x;
            ymin[i] = ymax[i] = v[i].y;
            rects.insert(0);
        }
    }
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

        int xsize = 2*(xmax[x]-xmin[x]+ymax[x]-ymin[x]);
        int ysize = 2*(xmax[y]-xmin[y]+ymax[y]-ymin[y]);
        rects.erase(rects.find(xsize));
        rects.erase(rects.find(ysize));

        xmin[x] = min(xmin[x], xmin[y]);
        xmax[x] = max(xmax[x], xmax[y]);
        ymin[x] = min(ymin[x], ymin[y]);
        ymax[x] = max(ymax[x], ymax[y]);
        int size = 2*(xmax[x]-xmin[x]+ymax[x]-ymin[x]);
        rects.insert(size);
        return true;
    }
    int smallest() {
        return *rects.begin();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    vt<pii> v(N);
    rep(i,0,N) {
        cin >> v[i].x >> v[i].y;
    }
    DSU dsu(N, v);
    rep(i,0,M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dsu.unite(a, b);
        cout << dsu.smallest() << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}