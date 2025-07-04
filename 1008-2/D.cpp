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

struct state {
    char op1, op2;
    ll v1, v2;
};

int T, N;
state a[35];
pll best[35];
pll dp[35];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,0,N+1) {
            dp[i] = {0, 0};
            best[i] = {0, 0};
        }
        rep(i,0,N) {
            cin >> a[i].op1 >> a[i].v1 >> a[i].op2 >> a[i].v2;
        }
        best[N-1] = {1, 1};
        rrep(i,N-2,0) {
            best[i] = best[i+1];
            if (a[i+1].op1 == 'x') {
                best[i].x = max(best[i+1].x*a[i+1].v1, best[i+1].x+(a[i+1].v1-1)*best[i+1].y);
            }
            if (a[i+1].op2 == 'x') {
                best[i].y = max(best[i+1].y*a[i+1].v2, best[i+1].y+(a[i+1].v2-1)*best[i+1].x);
            }
        }
        // cout << "best: " << endl;
        // rep(i,0,N) {
        //     cout << best[i].x << ' ' << best[i].y << endl;
        // }

        dp[0] = {1, 1};
        rep(i,1,N+1) {
            ll more = 0;
            if (a[i-1].op1 == '+') {
                more += a[i-1].v1;
            } else {
                more += (a[i-1].v1-1)*dp[i-1].x;
            }
            if (a[i-1].op2 == '+') {
                more += a[i-1].v2;
            } else {
                more += (a[i-1].v2-1)*dp[i-1].y;
            }
            dp[i] = dp[i-1];
            if (best[i-1].x > best[i-1].y) {
                dp[i].x += more;
            } else {
                dp[i].y += more;
            }
        }
        ll ans = dp[N].x+dp[N].y;
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}