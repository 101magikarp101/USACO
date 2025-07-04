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

int N, K;
int a[2005];
int dp[2005][2005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    K--;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j][0] = dp[i][j][1] = 1e9;
        }
    }
    dp[K][K][0] = dp[K][K][1] = 0;
    for (int l = 2; l <= N; l++) {
        for (int i = 0; i+l-1 < N; i++) {
            int r = i+l-1;
            if (dp[i+1][r][0]+1 < a[i]) {
                dp[i][r][0] = min(dp[i][r][0], dp[i+1][r][0]+1);
            }
            if (dp[i+1][r][1]+(r-i) < a[i]) {
                dp[i][r][0] = min(dp[i][r][0], dp[i+1][r][1]+(r-i));
            }
            if (dp[i][r-1][0]+(r-i) < a[r]) {
                dp[i][r][1] = min(dp[i][r][1], dp[i][r-1][0]+(r-i));
            }
            if (dp[i][r-1][1]+1 < a[r]) {
                dp[i][r][1] = min(dp[i][r][1], dp[i][r-1][1]+1);
            }
        }
    }
    ll ans = min(dp[0][N-1][0], dp[0][N-1][1]);
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}