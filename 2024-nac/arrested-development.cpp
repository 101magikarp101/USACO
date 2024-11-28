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
pii arr[55];
int a[2500005], b[2500005];

int solve(int x) {
    if (x < 0) return INT_MIN;
    int ans = INT_MAX;
    rep(i,0,x+1) {
        ckmin(ans, a[i]+b[x-i]);
    }
    // cout << "x: " << x << " ans: " << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    cin >> N;
    int n = N/2, m = N-n;
    rep(i,0,N) cin >> arr[i].x >> arr[i].y;
    if (N == 1) {
        cout << min(arr[0].x, arr[0].y) << endl;
        return 0;
    }
    rep(i,0,2500005) a[i] = INT_MAX;
    rep(i,0,2500005) b[i] = INT_MAX;
    int s1 = 0, s2 = 0;
    rep(i,0,n) {
        s2 += arr[i].y;
    }
    ckmin(a[s1], s2);
    rep(i,1,1<<n) {
        int prev = (i-1)^((i-1)>>1);
        int g = i^(i>>1);
        int j = __builtin_ctz(g^prev);
        if (g&(1<<j)) {
            s1 += arr[j].x;
            s2 -= arr[j].y;
        } else {
            s1 -= arr[j].x;
            s2 += arr[j].y;
        }
        // cout << "s1: " << s1 << " s2: " << s2 << endl;
        ckmin(a[s1], s2);
    }
    s1 = 0, s2 = 0;
    rep(i,0,m) {
        s2 += arr[i+n].y;
    }
    ckmin(b[s1], s2);
    rep(i,1,1<<m) {
        int prev = (i-1)^((i-1)>>1);
        int g = i^(i>>1);
        int j = __builtin_ctz(g^prev);
        if (g&(1<<j)) {
            s1 += arr[j+n].x;
            s2 -= arr[j+n].y;
        } else {
            s1 -= arr[j+n].x;
            s2 += arr[j+n].y;
        }
        // cout << "s1: " << s1 << " s2: " << s2 << endl;
        ckmin(b[s1], s2);
    }
    rep(i,1,2500005) {
        a[i] = min(a[i], a[i-1]);
    }
    rep(i,1,2500005) {
        b[i] = min(b[i], b[i-1]);
    }
    // cout << "a: ";
    // rep(i,0,200) cout << a[i] << " ";
    // cout << endl;
    // cout << "b: ";
    // rep(i,0,200) cout << b[i] << " ";
    // cout << endl;
    int l = 0, r = 2500000;
    while (l < r) {
        int m = (l+r)/2;
        if (m >= solve(m)) {
            r = m;
        } else {
            l = m+1;
        }
    }
    int ans = max(solve(l), l);
    ckmin(ans, max(solve(l-1), l-1));
    cout << ans << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
    cerr << "Time: " << duration.count() << "ms" << endl;
    return 0;
}