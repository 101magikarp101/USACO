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

int R, C, N, P;
int a[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> R >> C >> N >> P;
    vt<int> ans(N+1,0);
    rep(i,0,R) rep(j,0,C) cin >> a[i][j];
    rep(i,0,R) rep(j,0,C-1) {
        if (a[i][j] != 0 && a[i][j+1] != 0) {
            int ma = max(a[i][j], a[i][j+1]);
            int mi = min(a[i][j], a[i][j+1]);
            if (P >= ma) {
                ans[mi+P-ma]++;
            }
            if (P >= mi) {
                int res = ma+P-mi;
                if (res <= N) {
                    ans[res]++;
                }
            }
        }
    }
    rep(i,0,R-1) rep(j,0,C) {
        if (a[i][j] != 0 && a[i+1][j] != 0) {
            int ma = max(a[i][j], a[i+1][j]);
            int mi = min(a[i][j], a[i+1][j]);
            if (P >= ma) {
                ans[mi+P-ma]++;
            }
            if (P >= mi) {
                int res = ma+P-mi;
                if (res <= N) {
                    ans[res]++;
                }
            }
        }
    }
    int cnt = 0;
    rep(i,1,N+1) {
        if (i == P) continue;
        cnt += ans[i] > 0;
    }
    cout << cnt << '/' << N-1 << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}