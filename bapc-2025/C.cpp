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

int N;
int a[300005];
bool dp[1<<22], bits[22][1<<22];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    vt<int> b[22];
    rep(i,0,N) {
        cin >> a[i];
        rrep(j,21,0) {
            if (a[i] & (1 << j)) {
                b[j].pb(a[i]);
                break;
            }
        }
    }
    memset(dp, 0, sizeof dp);
    rep(i,0,22) {
        rep(j,0,1<<22) {
            bits[i][j] = 0;
        }
    }
    if (!b[0].empty()) dp[1] = 1;
    rep(i,1,22) {
        each(j,b[i]) {
            int mask = ((1<<(i+1))-1)^j;
            bits[i][mask] = 1;
        }
        rrep(m,(1<<(i+1))-1,0) {
            rep(j,0,i+1) {
                if (((m>>j)&1) == 0 && bits[i][m|(1<<j)]) {
                        bits[i][m] = 1;
                        break;
                }
            }
        }
        dp[1<<i] = !b[i].empty();
        rep(j,0,1<<i) {
            if (dp[j] && bits[i][j]) {
                dp[j|(1<<i)] = 1;
            }
        }
    }
    int ans = 0;
    rep(i,0,1<<22) {
        if (dp[i]) {
            ans = max(ans, __builtin_popcount(i));
        }
    }
    cout << ans << endl;


    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}