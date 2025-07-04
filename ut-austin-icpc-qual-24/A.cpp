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

struct circle {
    int x, y, r;
};

int N, M, K;
circle a[1005];
bool l[1005], r[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    DSU dsu(K);
    for (int i = 0; i < K; i++) {
        for (int j = i+1; j < K; j++) {
            int dx = a[i].x-a[j].x;
            int dy = a[i].y-a[j].y;
            int dr = a[i].r+a[j].r;
            if (dx*dx+dy*dy <= dr*dr) {
                dsu.unite(i, j);
            }
        }
    }
    for (int i = 0; i < K; i++) {
        int j = dsu.get(i);
        if (a[i].r >= a[i].x) l[j] = 1;
        if (a[i].y+a[i].r >= N) l[j] = 1;
        if (a[i].x+a[i].r >= M) r[j] = 1;
        if (a[i].r >= a[i].y) r[j] = 1;
    }
    bool ans = 1;
    for (int i = 0; i < K; i++) {
        if (l[i] && r[i]) {
            ans = 0;
            break;
        }
    }
    cout << (ans?"S":"N") << endl;
    return 0;
}