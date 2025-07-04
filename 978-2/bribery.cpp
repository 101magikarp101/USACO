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

int T, N;
int a[100005];
vt<int> adj[100005];
int cols[100005][3];
int best[100005][3][3];

void dfs(int u) {
    cols[u][a[u]] = 1;
    for (int v : adj[u]) {
        dfs(v);
        for (int i = 0; i < 3; i++) {
            cols[u][i] += cols[v][i];
        }
    }
}

void getbest(int u, int c1, int c2) {
    best[u][c1][c2] = cols[u][c1]-cols[u][c2];
    for (int v : adj[u]) {
        getbest(v, c1, c2);
        best[u][c1][c2] = min(best[u][c1][c2], best[v][c1][c2]);
    }
}

int solve1(int u, int c1, int c2, int c3) {
    // cout << "u: " << u << " c1: " << c1 << " c2: " << c2 << " c3: " << c3 << endl;
    int ans = INT_MAX;
    vt<pii> resv, resw;
    int i = 0;
    for (int v : adj[u]) {
        ans = min(ans, solve1(v, c1, c2, c3));
        // cout << "u: " << u << " v: " << v << " best: " << best[v][c1][c2] << " " << best[v][c1][c3] << endl;
        resv.pb({best[v][c1][c2], i});
        resw.pb({best[v][c1][c3], i});
        i++;
    }
    if (sz(resv) <= 1) return ans;
    sort(all(resv));
    sort(all(resw));
    if (resv[0].y != resw[0].y) {
        ans = min(ans, cols[1][c2]+cols[1][c3]+resv[0].x+resw[0].x);
    } else {
        ans = min(ans, cols[1][c2]+cols[1][c3]+min(resv[0].x+resw[1].x, resv[1].x+resw[0].x));
    }
    // cout << "u: " << u << " c1: " << c1 << " c2: " << c2 << " c3: " << c3 << " ans: " << ans << endl;
    return ans;
}

int solve2(int u, int c1, int c2, int c3) {
    int ans = INT_MAX;
    int b = 0;
    for (int v : adj[u]) {
        ans = min(ans, solve2(v, c1, c2, c3));
        b = min(b, best[v][c2][c3]);
    }
    ans = min(ans, cols[1][c2]+cols[1][c3]+cols[u][c1]-cols[u][c2]+b);
    return ans;
}

int solve(int c1, int c2, int c3) {
    int ans = INT_MAX;
    ans = min(ans, solve1(1, c1, c2, c3));
    // cout << "solve1: " << ans << " " << c1 << " " << c2 << " " << c3 << endl;
    ans = min(ans, solve2(1, c1, c2, c3));
    // cout << "solve2: " << ans << " " << c1 << " " << c2 << " " << c3 << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        string s; cin >> s;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'T') {
                a[i+1] = 0;
            } else if (s[i] == 'J') {
                a[i+1] = 1;
            } else {
                a[i+1] = 2;
            }
        }
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            cols[i][0] = cols[i][1] = cols[i][2] = 0;
        }
        for (int i = 2; i <= N; i++) {
            int p; cin >> p;
            adj[p].pb(i);
        }
        dfs(1);
        getbest(1,0,1);
        getbest(1,0,2);
        getbest(1,1,2);
        getbest(1,1,0);
        getbest(1,2,0);
        getbest(1,2,1);
        int ans = INT_MAX;
        ans = min(ans, solve(0, 1, 2));
        ans = min(ans, solve(0, 2, 1));
        ans = min(ans, solve(1, 0, 2));
        ans = min(ans, solve(1, 2, 0));
        ans = min(ans, solve(2, 0, 1));
        ans = min(ans, solve(2, 1, 0));
        cout << ans << endl;
    }
    return 0;
}