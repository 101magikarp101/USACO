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
int a[200005];

int calc(int x, int k) {
    // if (x == (1<<k)) return 1;
    // return __builtin_popcount(x) << k;
    int ans = 0;
    rrep(i,k,0) {
        if (x & (1<<i)) {
            ans += (1<<(k-i));
        }
    }
    // cout << "calc: " << x << " " << k << " " << ans << endl;
    return ans;
}

int solve(int x1, int y1, int x2, int y2, int a, int b, int k) {
    int xx1 = a << k;
    int xx2 = (a+1) << k;
    int yy1 = b << k;
    int yy2 = (b+1) << k;
    // cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << " xx1: " << xx1 << " yy1: " << yy1 << " xx2: " << xx2 << " yy2: " << yy2 << " a: " << a << " b: " << b << " k: " << k << endl;
    if (xx1 == x1 && xx2 == x2 && yy2 == y2) {
        return calc(yy2-y1, k);
    }
    if (xx1 == x1 && xx2 == x2 && yy1 == y1) {
        return calc(y2-yy1, k);
    }
    if (xx1 == x1 && yy1 == y1 && yy2 == y2) {
        return calc(x2-xx1, k);
    }
    if (xx2 == x2 && yy1 == y1 && yy2 == y2) {
        return calc(xx2-x1, k);
    }

    int ans = 0;
    //bottom left
    int l = max(x1, xx1);
    int r = min(x2, xx1+(1<<(k-1)));
    int d = max(y1, yy1);
    int u = min(y2, yy1+(1<<(k-1)));
    if (l < r && d < u) {
        ans += solve(l, d, r, u, a<<1, b<<1, k-1);
    }
    //bottom right
    l = max(x1, xx1+(1<<(k-1)));
    r = min(x2, xx2);
    d = max(y1, yy1);
    u = min(y2, yy1+(1<<(k-1)));
    if (l < r && d < u) {
        ans += solve(l, d, r, u, (a<<1)^1, b<<1, k-1);
    }
    //top left
    l = max(x1, xx1);
    r = min(x2, xx1+(1<<(k-1)));
    d = max(y1, yy1+(1<<(k-1)));
    u = min(y2, yy2);
    if (l < r && d < u) {
        ans += solve(l, d, r, u, a<<1, (b<<1)^1, k-1);
    }
    //top right
    l = max(x1, xx1+(1<<(k-1)));
    r = min(x2, xx2);
    d = max(y1, yy1+(1<<(k-1)));
    u = min(y2, yy2);
    if (l < r && d < u) {
        ans += solve(l, d, r, u, (a<<1)^1, (b<<1)^1, k-1);
    }
    // cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << " xx1: " << xx1 << " yy1: " << yy1 << " xx2: " << xx2 << " yy2: " << yy2 << " a: " << a << " b: " << b << " k: " << k << endl;
    // cout << "ans: " << ans << endl;
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
        int x1, y1, x2, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << solve(x1, y1, x2, y2, 0, 0, 20) << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}