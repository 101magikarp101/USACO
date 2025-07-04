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

struct edge {
    int u, v, w;
    bool operator<(const edge &a) const { return w < a.w; }
};

int T, N, M;
string nar = "narek";
vt<edge> adj[1003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            adj[i].clear();
            string s; cin >> s;
            for (int j = 0; j < 5; j++) {
                int cur = j;
                int score = 0;
                int gpt = 0;
                for (int k = 0; k < M; k++) {
                    for (int l = 0; l < 5; l++) {
                        if (s[k] == nar[l]) {
                            gpt++;
                            break;
                        }
                    }
                    if (s[k] == nar[cur]) {
                        cur++;
                        if (cur == 5) {
                            score += 5;
                            gpt -= 5;
                            cur = 0;
                        }
                    }
                }
                adj[i].pb({j, cur, score-gpt});
            }
        }
        int ans = 0;
        vt<vt<int>> dp(N, vt<int>(5, -1e9));
        for (edge e : adj[0]) {
            if (e.u != 0) continue;
            dp[0][e.v] = max(dp[0][e.v], e.w);
        }
        for (int i = 1; i < N; i++) {
            for (edge e : adj[i]) {
                if (e.u != 0) continue;
                dp[i][e.v] = max(dp[i][e.v], e.w);
            }
            for (int j = 0; j < 5; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            for (edge e : adj[i]) {
                dp[i][e.v] = max(dp[i][e.v], dp[i-1][e.u]+e.w);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}