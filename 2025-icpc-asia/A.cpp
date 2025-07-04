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

int N, M;
char a[2005][2005];
ll row[2005], col[2005];
ll dp1[2005][2005], dp2[2005][2005], rdp[2005], cdp[2005];

ll c4(ll n) {
    return n*(n-1)*(n-2)*(n-3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    rep(i,0,N) rep(j,0,M) cin >> a[i][j];
    rep(i,0,N) rep(j,0,M) {
        if (a[i][j] == '.') {
            row[i]++;
            col[j]++;
        }
    }
    ll ans = 0;
    rep(i,0,N) {
        ans += c4(row[i]);
    }
    rep(i,0,M) {
        ans += c4(col[i]);
    }
    // cout << "ans: " << ans << endl;
    rep(i,0,N) rep(j,0,M) {
        if (a[i][j] == '.') {
            ll res = (row[i]-1)*(col[j]-1)*(col[j]-2)*2;
            ans += res;
            res = (col[j]-1)*(row[i]-1)*(row[i]-2)*2;
            ans += res;
        }
    }
    // cout << "ans: " << ans << endl;
    rep(i,0,N) rep(j,0,M) {
        if (a[i][j] == '.') {
            dp1[i][j] = col[j]-1;
            rdp[i] += dp1[i][j];
            dp2[i][j] = row[i]-1;
            cdp[j] += dp2[i][j];
        }
    }
    rep(i,0,N) rep(j,0,M) {
        if (a[i][j] == '.') {
            ll res = dp1[i][j]*(rdp[i]-dp1[i][j]);
            ans += res;
            res = dp2[i][j]*(cdp[j]-dp2[i][j]);
            ans += res;
        }
    }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}