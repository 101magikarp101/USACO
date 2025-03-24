#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int T, N;
ll dp[60][60], dp2[60][60];
int X = 60;

int hbit(ll x) {
    return 63 - __builtin_clzll(x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    rep(i,0,X) {
        rep(j,0,X) {
            dp[i][j] = -1;
            dp2[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    repl(n,1,X) {
        rep(i,0,X) {
            rep(j,0,X) {
                dp2[i][j] = dp[i][j];
                if (i-n >= 0 && dp[i-n][j] != -1) {
                    if (dp2[i][j] == -1) dp2[i][j] = dp[i-n][j]+(1LL<<n);
                    else ckmin(dp2[i][j], dp[i-n][j]+(1LL<<n));
                }
                if (j-n >= 0 && dp[i][j-n] != -1) {
                    if (dp2[i][j] == -1) dp2[i][j] = dp[i][j-n]+(1LL<<n);
                    else ckmin(dp2[i][j], dp[i][j-n]+(1LL<<n));
                }
            }
        }
        // cout << "dp2: " << endl;
        // rep(i,0,X) {
        //     rep(j,0,X) {
        //         cout << dp2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        rep(i,0,X) {
            rep(j,0,X) {
                dp[i][j] = dp2[i][j];
                dp2[i][j] = -1;
            }
        }
    }
    rrep(i,X-1,0) {
        rrep(j,X-1,0) {
            dp2[i][j] = dp[i][j];
            if (dp2[i][j] == -1) dp2[i][j] = LLONG_MAX;
            if (i+1 < X) ckmin(dp2[i][j], dp2[i+1][j]);
            if (j+1 < X) ckmin(dp2[i][j], dp2[i][j+1]);
        }
    }
    cin >> T;
    while (T--) {
        ll x, y; cin >> x >> y;
        int a = hbit(x), b = hbit(y);
        // cout << a << " " << b << endl;
        ll ans = dp2[a+1][b+1];
        if (x == y) {
            cout << 0 << endl;
            continue;
        } else if (x == 0) {
            cout << dp[0][b+1] << endl;
            continue;
        } else if (y == 0) {
            cout << dp[a+1][0] << endl;
            continue;
        }
        while (a>=0 && b>=0) {
            ll res = dp[a][b];
            if (res != -1) ckmin(ans, res);
            a--; b--;
            if (a < 0 || b < 0) break;
            if (((x>>a)&1) != ((y>>b)&1)) break;
        }
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}