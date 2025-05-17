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

int T, N, M;
int fac[1000005], ifac[1000005];

int ad(int a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD2;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD2);
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
    return binpow(a, MOD2-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int perm(int n, int k) {
    if (k > n || k < 0 || n < 0) return 0;
    return mul(fac[n], ifac[n-k]);
}

int nck(int n, int k) {
    if (k > n || k < 0 || n < 0) return 0;
    return mul(mul(fac[n], ifac[k]), ifac[n-k]);
}

void pre(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    ifac[n] = inv(fac[n]);
    for (int i = n-1; i >= 0; i--) {
        ifac[i] = mul(ifac[i+1], i+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    pre(1000000);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        int mid = (3*N+1)/2;
        int idx = -1;
        vt<vt<int>> a(3, vt<int>(2, 0));
        int big = 3*N/2, small = 3*N/2;
        rep(i,0,M) {
            int x, y; cin >> x >> y;
            if (y > mid) {
                a[(x-1)/N][1]++;
                big--;
            } else if (y < mid) {
                a[(x-1)/N][0]++;
                small--;
            }
            else idx = (x-1)/N;
        }
        if (idx == -1) {
            int ans = 0;
            rep(i,0,3) {
                int res = mul(nck(small, N/2-a[i][0]), nck(big, N/2-a[i][1]));
                res = mul(res, fac[N-a[i][0]-a[i][1]]);
                int rsmall = small-(N/2-a[i][0]);
                int rbig = big-(N/2-a[i][1]);
                res = mul(res, fac[rsmall+rbig]);
                ans = ad(ans, res);
            }
            cout << ans << endl;
        } else {
            int ans = mul(nck(small, N/2-a[idx][0]), nck(big, N/2-a[idx][1]));
            ans = mul(ans, fac[N/2*2-a[idx][0]-a[idx][1]]);
            // cout << "ans: " << ans << endl;
            int rsmall = small-(N/2-a[idx][0]);
            int rbig = big-(N/2-a[idx][1]);
            // cout << "rsmall: " << rsmall << " rbig: " << rbig << endl;
            ans = mul(ans, fac[rsmall+rbig]);
            cout << ans << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}