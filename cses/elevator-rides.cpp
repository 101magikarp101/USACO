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

int N;
ll X;
ll a[21];
pll dp[1<<20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 1<<N; i++) {
        dp[i] = {(ll)1e18,0};
    }
    dp[0] = {0,X};
    for (int m = 1; m < 1<<N; m++) {
        for (int i = 0; i < N; i++) {
            if (m&(1<<i)) {
                int n = m^(1<<i);
                pll p = dp[n];
                if (a[i] > p.y) {
                    p.x++;
                    p.y = X-a[i];
                } else {
                    p.y -= a[i];
                }
                if (p.x < dp[m].x) {
                    dp[m] = p;
                } else if (p.x == dp[m].x && p.y > dp[m].y) {
                    dp[m] = p;
                } 
            }
        }
    }
    ll ans = dp[(1<<N)-1].x+1;
    cout << ans << endl;
    return 0;
}