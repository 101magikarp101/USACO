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
int dp[5005][5005];
int a[5005][5005], b[5005][5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x > 0) {
            if (cnt-x < 0) continue;
            // cout << "cnt:" << cnt << " x:" << x << " cnt-x:" << cnt-x << endl;
            a[cnt-x][x]++;
        } else if (x < 0) {
            if (cnt+x < 0) continue;
            // cout << "cnt:" << cnt << " x:" << x << " cnt+x:" << cnt+x << endl;
            b[-x][cnt+x]++;
        } else {
            int sum = 0;
            for (int j = min(M, cnt); j >= 0; j--) {
                sum += a[j][cnt-j];
                dp[j][cnt-j] += sum;
                if (cnt-j >= M) break;
            }
            sum = 0;
            for (int j = min(M, cnt); j >= 0; j--) {
                sum += b[cnt-j][j];
                dp[cnt-j][j] += sum;
                if (cnt-j >= M) break;
            }
            cnt++;
            for (int j = min(M, cnt); j >= 0; j--) {
                // dp[j][cnt-j] = max(dp[j-1][cnt-j], dp[j][cnt-j-1]);/
                if (j-1 >= 0) dp[j][cnt-j] = max(dp[j][cnt-j], dp[j-1][cnt-j]);
                if (cnt-j-1 >= 0) dp[j][cnt-j] = max(dp[j][cnt-j], dp[j][cnt-j-1]);
                if (cnt-j >= M) break;
            }
        }
    }
    int sum = 0;
    for (int j = min(M, cnt); j >= 0; j--) {
        sum += a[j][cnt-j];
        dp[j][cnt-j] += sum;
        if (cnt-j >= M) break;
    }
    sum = 0;
    for (int j = min(M, cnt); j >= 0; j--) {
        sum += b[cnt-j][j];
        dp[cnt-j][j] += sum;
        if (cnt-j >= M) break;
    }
    cnt++;
    for (int j = min(M, cnt); j >= 0; j--) {
        // dp[j][cnt-j] = max(dp[j-1][cnt-j], dp[j][cnt-j-1]);/
        if (j-1 >= 0) dp[j][cnt-j] = max(dp[j][cnt-j], dp[j-1][cnt-j]);
        if (cnt-j-1 >= 0) dp[j][cnt-j] = max(dp[j][cnt-j], dp[j][cnt-j-1]);
        if (cnt-j >= M) break;
    }
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    // cout << "a:" << endl;
    // for (int i = 0; i <= M; i++) {
    //     for (int j = 0; j <= M; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "b:" << endl;
    // for (int i = 0; i <= M; i++) {
    //     for (int j = 0; j <= M; j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "dp:" << endl;
    // for (int i = 0; i <= M; i++) {
    //     for (int j = 0; j <= M; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}