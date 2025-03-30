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

int ad(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int T, N, M, D;
char a[2005][2005];
int dp[2005][2005][2], pre[2005][2005];
int dist[2005];

int get(int i, int j, int d) {
    int l = max(0, j-d), r = min(M-1, j+d);
    return sub(pre[i][r], (l ? pre[i][l-1] : 0));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> M >> D;
        dist[0] = D;
        dist[1] = sqrtl(D*D-1);
        rep(i,0,N) {
            rep(j,0,M) {
                cin >> a[i][j];
            }
        }
        rep(i,0,N) rep(j,0,M) dp[i][j][0] = dp[i][j][1] = 0;
        rrep(i,N-1,0) {
            rep(j,0,M) {
                if (i == N-1) {
                    dp[i][j][0] = a[i][j] == 'X';
                } else {
                    dp[i][j][0] = a[i][j] == 'X' ? get(i+1,j,dist[1]) : 0;
                }
                pre[i][j] = dp[i][j][0];
                if (j) pre[i][j] = ad(pre[i][j], pre[i][j-1]);
            }
            rep(j,0,M) {
                dp[i][j][1] = a[i][j] == 'X' ? sub(get(i,j,dist[0]), dp[i][j][0]) : 0;
                dp[i][j][0] = ad(dp[i][j][0], dp[i][j][1]);
            }
            rep(j,0,M) {
                pre[i][j] = dp[i][j][0];
                if (j) pre[i][j] = ad(pre[i][j], pre[i][j-1]);
            }
        }
        int ans = pre[0][M-1];
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}