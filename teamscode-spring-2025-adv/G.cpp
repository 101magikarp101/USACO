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

int T, N;
int MAX = 1005;
int bi[1005][1005]; // n, k
int suf[1005][1005]; // n, k
int dp[1005][1005][2]; // idx, sum, 1/0

void pre(int n) {
    bi[0][0] = 1;
    rep(i, 1, n+1) {
        bi[i][0] = 1;
        rep(j, 1, i+1) {
            bi[i][j] = ad(bi[i-1][j], bi[i-1][j-1]);
        }
    }
    rep(i,1,n+1) {
        rrep(j,i,0) {
            suf[i][j] = ad(suf[i][j+1], bi[i][j]);
        }
    }
}

int solve(string s) {
    // if strict, starts with 1
    // vt<vt<vt<int>>> dp(sz(s)+1, vt<vt<int>>(sz(s)+1, vt<int>(2,0))); // idx, sum, 1/0
    int n = sz(s);
    vt<int> sus(n,0);
    sus[0] = s[0] == '1' ? 1 : 0;
    rep(i,1,n) {
        sus[i] = ad(ad(sus[i-1], sus[i-1]), s[i] == '1' ? 1 : 0);
    }
    rep(i,0,n+1) {
        rep(j,0,n+1) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }
    dp[n][0][0] = 1;
    rrep(i,n-1,0) {
        int k = n-i;
        if (s[i] == '0') {
            rep(j,0,k) {
                dp[i][j][0] = ad(dp[i+1][j][0], dp[i+1][j][1]);
            }
        } else {
            rep(j,0,k) {
                dp[i][j+1][1] = ad(dp[i+1][j][0], dp[i+1][j][1]);
                dp[i][j][0] = ad(dp[i][j][0], bi[k-1][j]);
            }
        }
    }
    int ans = 0;
    rep(i,0,n) {
        int k = n-i-1;
        rep(j,0,n) {
            int x = dp[i][j+1][1];
            if (i) x = ad(x, mul(sus[i-1], bi[k][j]));
            ans = ad(ans, mul(x, suf[k][j+2]));
        }
    }
    return ans;
}

void dec(string &s) {
    int n = sz(s);
    int i = n-1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '1';
        i--;
    }
    if (i < 0) {
        s = "1";
        return;
    }
    s[i] = '0';
    if (s[0] == '0' && n > 1) {
        s = s.substr(1, n-1);
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    pre(1000);
    string s, t; cin >> s >> t;
    dec(s);
    int ansr = solve(t);
    int ansl = solve(s);
    cout << sub(ansr, ansl) << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}