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
vt<int> adj[200005]; // back edges
int a[200005]; // forward edges
ll c[200005]; // cost
ll dp[200005][2]; // 0 = no change, 1 = change
bool vis[200005], loop[200005];
int loopsiz[200005];

void findloop(int x) {
    set<int> s;
    while (!vis[x]) {
        vis[x] = 1;
        s.insert(x);
        x = a[x];
    }
    if (s.count(x)) {
        // loop
        int cnt = 0;
        while (!loop[x]) {
            loop[x] = 1;
            x = a[x];
            cnt++;
        }
        loopsiz[x] = cnt;
    }
}

void branchdp(int x) {
    each(v,adj[x]) {
        branchdp(v);
        dp[x][0] += dp[v][1];
        dp[x][1] += min(dp[v][0], dp[v][1]);
    }
    dp[x][1] += c[x];
    // cout << "branchdp " << x << " " << dp[x][0] << " " << dp[x][1] << endl;
}

void outerdp(int x) {
    int siz = loopsiz[x];
    rep(i,0,siz) {
        each(y,adj[x]) {
            if (!loop[y]) {
                branchdp(y);
                if (siz != 1) dp[x][0] += dp[y][1];
                else dp[x][0] += min(dp[y][0], dp[y][1]);
                dp[x][1] += min(dp[y][0], dp[y][1]);
            }
        }
        dp[x][1] += c[x];
        // cout << "outerdp " << x << " " << dp[x][0] << " " << dp[x][1] << endl;
        x = a[x];
    }
}

ll linedp(vt<pll> &v, int l, int r) {
    if (l > r) return 0;
    vt<ll> dp(r-l+2);
    dp[0] = 0;
    dp[1] = v[l].y;
    rep(i,2,r-l+2) {
        dp[i] = min(dp[i-1] + v[l+i-1].y, dp[i-2] + v[l+i-2].x + v[l+i-1].y);
    }
    return dp[r-l+1];
}

ll innerdp(int x) {
    int siz = loopsiz[x];
    vt<pll> v(siz);
    rep(i,0,siz) {
        v[i] = {dp[x][0], dp[x][1]};
        x = a[x];
    }
    ll res = linedp(v, 0, siz-1);
    // cout << "innerdp " << res << endl;
    if (siz > 1) ckmin(res, linedp(v, 1, siz-2) + v[0].y + v[siz-1].x);
    else ckmin(res, v[0].x);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    rep(i,1,N+1) {
        cin >> a[i];
        adj[a[i]].pb(i);
        loopsiz[i] = -1;
        dp[i][0] = dp[i][1] = 0;
        vis[i] = loop[i] = 0;
    }
    rep(i,1,N+1) cin >> c[i];
    // find loops
    rep(i,1,N+1) {
        if (!vis[i]) {
            findloop(i);
        }
    }
    // cout << "loop: ";
    // rep(i,1,N+1) cout << loop[i] << " ";
    // cout << endl;
    // cout << "loopsiz: ";
    // rep(i,1,N+1) cout << loopsiz[i] << " ";
    // cout << endl;
    // outer dp
    rep(i,1,N+1) {
        if (loopsiz[i] != -1) {
            outerdp(i);
        }
    }
    // inner dp
    ll ans = 0;
    rep(i,1,N+1) {
        if (loopsiz[i] != -1) {
            ans += innerdp(i);
        }
    }
    cout << ans << endl;


    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}