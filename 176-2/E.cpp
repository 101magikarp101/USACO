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

int T, N, M, A, B;
int dp[31][2][2][2]; // idx, not zero, strict a, strict b

int solve(int idx, bool nz, bool sa, bool sb) {
    if (idx == -1) {
        return 1;
    }
    if (dp[idx][nz][sa][sb] != -1) return dp[idx][nz][sa][sb];
    int res = 0;
    bool cur_a = (A>>idx)&1, cur_b = (B>>idx)&1;
    rep(a,0,2) rep(b,0,2) rep(x,0,2) {
        bool nnz = nz;
        bool nsa = sa, nsb = sb;
        if (sa && a > cur_a) continue;
        if (sb && b > cur_b) continue;
        if (!nz && sa && (a^x) > cur_a) continue;
        if (!nz && sb && (b^x) > cur_b) continue;
        if (!nz && x && !a) continue;
        if (!nz && x && !b) continue;
        if (a < cur_a) nsa = 0;
        if (b < cur_b) nsb = 0;
        if (x == 1) nnz = 1;
        res = ad(res, solve(idx-1, nnz, nsa, nsb));
    }
    return dp[idx][nz][sa][sb] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    int two = inv(2);
    while (T--) {
        cin >> N >> M >> A >> B;
        rep(i,0,31) {
            rep(j,0,2) {
                rep(k,0,2) {
                    rep(l,0,2) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        int cnt11 = mul(A+1, B+1);
        int cnt22 = solve(30, 0, 1, 1);
        cnt22 = sub(cnt22, cnt11);
        cnt22 = mul(cnt22, mul(sub(binpow(2, N), 2), sub(binpow(2, M), 2)));
        int cnt12 = mul(A+1, mul(mul(mul(B+1, B), two), sub(binpow(2, M), 2)));
        int cnt21 = mul(B+1, mul(mul(mul(A+1, A), two), sub(binpow(2, N), 2)));
        int res = ad(ad(cnt11, cnt22), ad(cnt12, cnt21));
        cout << res << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}