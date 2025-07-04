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

struct state {
    int i, x, y, z;
    bool operator<(const state &a) const { 
        if (x == a.x) {
            return i < a.i;
        } else {
            return x < a.x;
        }
    }
};

int N, x, y, z;
state a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> x >> y >> z;
    int t = x+y+z;
    for (int i = 1; i <= N; i++) {
        cin >> a[i].x;
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i].y;
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i].z;
    }
    for (int i = 1; i <= N; i++) {
        a[i].i = i;
    }
    set<state> s;
    sort(a+1,a+N+1, [&](state a, state b) {
        return a.x < b.x;
    });
    for (int i = 1; i <= t; i++) {
        s.insert(a[i]);
    }
    sort(a+1,a+N+1, [&](state a, state b) {
        return a.y < b.y;
    });
    for (int i = 1; i <= t; i++) {
        s.insert(a[i]);
    }
    sort(a+1,a+N+1, [&](state a, state b) {
        return a.z < b.z;
    });
    for (int i = 1; i <= t; i++) {
        s.insert(a[i]);
    }
    vt<state> v;
    for (auto i : s) {
        v.pb(i);
    }
    vt<vt<vt<ll>>> dp(sz(v)+1, vt<vt<ll>>(y+1, vt<ll>(z+1, 1e18)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= sz(v); i++) {
        for (int j = 0; j <= y; j++) {
            for (int k = 0; k <= z; k++) {
                dp[i][j][k] = dp[i-1][j][k];
                if (i-(j+k) <= x) dp[i][j][k] += v[i-1].x;
                if (j) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][k]+v[i-1].y);
                if (k) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k-1]+v[i-1].z);
            }
        }
    }
    cout << dp[sz(v)][y][z] << endl;
    return 0;
}