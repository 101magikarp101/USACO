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

int N, M;
vt<int> res;
int dp[5005][21];
bool vis[5005][21];

void solve(int n, int m) {
    if (vis[n][m]) return;
    vis[n][m] = 1;
    if (n == 0) {
        dp[n][m] = 0;
        return;
    }
    if (m == 1) {
        dp[n][m] = n;
        if (M == 1) {
            res.pb(1);
        }
        return;
    } else {
        int best = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int l = i-1, r = n-i;
            solve(l, m-1);
            solve(r, m);
            int cur = max(dp[l][m-1], dp[r][m])+1;
            if (cur < best) {
                best = cur;
                if (M == m) {
                    res.clear();
                }
            }
            if (cur == best && M == m) {
                res.pb(i);
            }
        }
        dp[n][m] = best;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    solve(N, M);
    cout << dp[N][M] << " ";
    if (sz(res) == 1) {
        cout << res[0] << endl;
    } else {
        cout << res[0] << "-" << res[sz(res)-1] << endl;
    }
    return 0;
}