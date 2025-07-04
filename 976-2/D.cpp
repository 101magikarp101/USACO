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

struct seg {
    int a, d, k;
    bool operator< (const seg &s) const {
        return a < s.a;
    }
};

int T, N, M;
vt<seg> v[11][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        DSU dsu(N+1);
        for (int i = 1; i <= 10; i++) {
            for (int j = 0; j < i; j++) {
                v[i][j].clear();
            }
        }
        for (int i = 0; i < M; i++) {
            int x, y, z; cin >> x >> y >> z;
            v[y][x%y].pb({x, y, z});
        }
        for (int i = 1; i <= 10; i++) {
            for (int j = 0; j < i; j++) {
                sort(all(v[i][j]));
            }
        }
        for (int i = 1; i <= 10; i++) {
            for (int j = 0; j < i; j++) {
                if (sz(v[i][j]) == 0) continue;
                int cur = 0;
                mset<int> s;
                for (int k = j; k <= N; k += i) {
                    while (!s.empty() && *s.begin() < k) {
                        s.erase(s.begin());
                    }
                    if (!s.empty() && k > j) {
                        // cout << "unite " << k << " " << k-i << endl;
                        dsu.unite(k,k-i);
                    }
                    while (cur < sz(v[i][j]) && v[i][j][cur].a <= k) {
                        s.insert(v[i][j][cur].a+v[i][j][cur].d*v[i][j][cur].k);
                        cur++;
                    }
                }
            }
        }
        set<int> ans;
        for (int i = 1; i <= N; i++) {
            ans.insert(dsu.get(i));
        }
        cout << sz(ans) << endl;
    }
    return 0;
}