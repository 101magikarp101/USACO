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
ll K;

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

int solve(int n) {
    int ans = 0;
    int x = N;
    while (x) {
        ans = mul(ans, n);
        ans = ad(ans, x%n);
        x /= n;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> K;
        int ans = 0;
        int sq = -1;
        repl(i,2,K+1) {
            if (i*i > N) {
                sq = i;
                break;
            }
            ans = ad(ans, solve(i));
        }
        if (sq == -1) {
            cout << ans << endl;
            continue;
        }
        int start = N/sq;
        // cout << "start: " << start << endl;
        int two = inv(2);
        int six = inv(6);
        rrep(i,start,1) {
            int l = N/(i+1)+1;
            if (l > K) break;
            int a = N/l;
            int b = N%l;
            int n = b/a;
            ll last = l+n;
            last = min(last, K);
            n = last-l;
            // cout << "i: " << i << " l: " << l << " r: " << r << " a: " << a << " b: " << b << " n: " << n << endl;
            int res = mul(a, n+1);
            // cout << "res: " << res << endl;
            res = ad(res, mul(l, mul(mul(b+b-n*a, n+1), two)));
            // cout << "res: " << res << endl;
            res = ad(res, mul(b, mul(mul(n, n+1), two)));
            // cout << "res: " << res << endl;
            res = sub(res, mul(a, mul(mul(mul(n, n+1), 2*n+1), six)));
            // cout << "res: " << res << endl;
            ans = ad(ans, res);
        }
        if (K <= N) {
            cout << ans << endl;
            continue;
        }
        int res = mul(N, (K-N)%MOD2);
        ans = ad(ans, res);
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}