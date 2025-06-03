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

struct query {
    int x, y, z;
};

int T, N, Q;
int a[300005], idxs[300005];
int dp[600005];
pii ps[300005];
query qs[300005];

bool run() {
    vt<int> b(N,0);
    rep(i,0,N) {
        b[i] = dp[i];
    }
    rep(i,0,Q) {
        query q = qs[i];
        int x = q.x, y = q.y, z = q.z;
        b[z] = min(b[x], b[y]);
    }
    rep(i,0,N) {
        if (b[i] != a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> Q;
        rep(i,0,N+Q) {
            dp[i] = 0;
        }
        rep(i,0,N) {
            cin >> a[i];
            idxs[i] = i;
        }
        rep(i,0,Q) {
            int x, y, z;
            cin >> x >> y >> z;
            x--; y--; z--;
            qs[i] = {x, y, z};
            pii p = {idxs[x], idxs[y]};
            ps[i] = p;
            idxs[z] = i + N;
        }
        rep(i,0,N) {
            dp[idxs[i]] = a[i];
        }
        rrep(i,Q-1,0) {
            pii p = ps[i];
            ckmax(dp[p.x], dp[i+N]);
            ckmax(dp[p.y], dp[i+N]);
        }
        if (!run()) {
            cout << -1 << endl;
            continue;
        }
        rep(i,0,N) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}