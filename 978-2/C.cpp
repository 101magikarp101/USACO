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
int a[100005][2];
int dp[100005][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        string s; cin >> s;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'A') {
                a[i+1][0] = 1;
            } else {
                a[i+1][0] = 0;
            }
        }
        cin >> s;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'A') {
                a[i+1][1] = 1;
            } else {
                a[i+1][1] = 0;
            }
        }
        for (int i = 0; i <= N; i++) {
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        }
        dp[0][0] = 0;
        for (int i = 2; i <= N; i++) {
            int cnt = a[i-1][0]+a[i-1][1]+a[i][0];
            if (i%3==2) {
                int res = (cnt >= 2);
                dp[i][0] = max(dp[i][0], dp[i-2][2]+res);
            }
            cnt = a[i-1][0]+a[i-1][1]+a[i][1];
            if (i%3==2) {
                int res = (cnt >= 2);
                dp[i][1] = max(dp[i][1], dp[i-2][2]+res);
            }
            if (i>=3 && i%3==0) {
                cnt = a[i-1][0]+a[i][0]+a[i][1];
                int res = (cnt >= 2);
                dp[i][2] = max(dp[i][2], dp[i-1][1]+res);
            }
            if (i>=3 && i%3==0) {
                cnt = a[i-1][1]+a[i][0]+a[i][1];
                int res = (cnt >= 2);
                dp[i][2] = max(dp[i][2], dp[i-1][0]+res);
            }
            if (i>=3 && i%3==0) {
                int cnt1 = a[i-2][0]+a[i-1][0]+a[i][0];
                int cnt2 = a[i-2][1]+a[i-1][1]+a[i][1];
                int res = (cnt1 >= 2) + (cnt2 >= 2);
                dp[i][2] = max(dp[i][2], dp[i-3][2]+res);
            }
            if (i>=4 && i%3==2) {
                int cnt1 = a[i-2][0]+a[i-1][0]+a[i][0];
                int cnt2 = a[i-3][1]+a[i-2][1]+a[i-1][1];
                int res = (cnt1 >= 2) + (cnt2 >= 2);
                dp[i][0] = max(dp[i][0], dp[i-3][0]+res);
            }
            if (i>=4 && i%3==2) {
                int cnt1 = a[i-3][0]+a[i-2][0]+a[i-1][0];
                int cnt2 = a[i-2][1]+a[i-1][1]+a[i][1];
                int res = (cnt1 >= 2) + (cnt2 >= 2);
                dp[i][1] = max(dp[i][1], dp[i-3][1]+res);
            }
        }
        // cout << "dp" << endl;
        // for (int i = 0; i <= N; i++) {
        //     cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
        // }
        cout << dp[N][2] << endl;
    }
    return 0;
}