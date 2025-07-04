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
int a[5005];
vt<int> ps[5005];
int gc[5005][5005];

void pre(int n) {
    rep(i,0,n+1) {
        rep(j,i,n+1) {
            gc[i][j] = i ? gc[j%i][i] : j;
            gc[j][i] = gc[i][j];
        }
    }
    rep(i,2,n+1) {
        if (sz(ps[i]) > 0) continue;
        ps[i].pb(i);
        for (int j = i + i; j <= n; j += i) {
            ps[j].pb(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    pre(5000);

    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,0,N) cin >> a[i];
        int g = a[0];
        rep(i,1,N) g = gc[g][a[i]];
        int one = 0;
        rep(i,0,N) {
            a[i] /= g;
            one += (a[i] == 1);
        }
        if (one != 0) {
            cout << N - one << endl;
            continue;
        }
        uset<int> vis;
        int ans = 1e9;
        rep(i,0,N) {
            if (vis.count(a[i])) continue;
            vis.insert(a[i]);
            int n = sz(ps[a[i]]);
            vt<int> dp(1<<n, 1e9);
            dp[0] = 0;
            rep(j,0,N) {
                int m = 0;
                rep(k,0,n) {
                    if (a[j] % ps[a[i]][k] != 0) {
                        m |= (1 << k);
                    }
                }
                // cout << "m: " << m << endl;
                dp[m] = 1;
            }
            // cout << "i: " << i << " n: " << n << endl;
            // rep(i,0,1<<n) {
            //     cout << i << ": " << dp[i] << endl;
            // }

            rep(x,0,1<<n) {
                rep(y,0,1<<n) {
                    if (dp[x] == 1e9 || dp[y] == 1e9) continue;
                    ckmin(dp[x | y], dp[x]+dp[y]);
                }
            }
            ckmin(ans, dp[(1<<n)-1]);
        }
        cout << N+ans-1 << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}