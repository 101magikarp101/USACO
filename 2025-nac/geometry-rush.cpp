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

int N, M, W, H;
pll a[100005], b[100005];
ll u[100005], d[100005];

int sign(ll x) {
    if (x >= 0) return 1;
    else return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M >> W >> H;
    rep(i,1,W+1) {
        u[i] = 1e9;
        d[i] = -1e9;
    }
    rep(i,0,N) {
        cin >> a[i].x >> a[i].y;
        ckmin(u[a[i].x], a[i].y);
    }
    rep(i,0,M) {
        cin >> b[i].x >> b[i].y;
        ckmax(d[b[i].x], b[i].y);
    }
    ll mi = 0, ma = 0;
    int i = 0, j = 0;
    rep(x,1,W+1) {
        while (i+1 < N && a[i+1].x <= x) {
            i++;
        }
        while (j+1 < M && b[j+1].x <= x) {
            j++;
        }
        pll up = {0,0};
        if (u[x] != 1e9) {
            up = {u[x], 1};
        } else {
            up = {(x-a[i].x)*(a[i].y-a[i+1].y), a[i].x-a[i+1].x};
            up.x += a[i].y*up.y;
        }
        up.x = up.y*(ma+1)-up.x;
        up.y *= 2;
        ll s = sign(up.x)*sign(up.y);
        up.x = abs(up.x);
        up.y = abs(up.y);
        ll k = 1+s*(up.x%up.y == 0 ? up.x/up.y : (s==1 ? up.x/up.y : up.x/up.y+1));
        ma++;
        if (k >= 0) {
            ma -= k*2;
        }
        pll down = {0,0};
        if (d[x] != -1e9) {
            down = {d[x], 1};
        } else {
            down = {(x-b[j].x)*(b[j].y-b[j+1].y), b[j].x-b[j+1].x};
            down.x += b[j].y*down.y;
        }
        down.x = down.x-down.y*(mi-1);
        down.y *= 2;
        s = sign(down.x)*sign(down.y);
        down.x = abs(down.x);
        down.y = abs(down.y);
        k = 1+s*(down.x%down.y == 0 ? down.x/down.y : (s==1 ? down.x/down.y : down.x/down.y+1));
        mi--;
        if (k >= 0) {
            mi += k*2;
        }
        // cout << "i: " << i << ", j: " << j << endl;
        // cout << "x: " << x << ", u: " << u[x] << ", d: " << d[x] << endl;
        // cout << "mi: " << mi << ", ma: " << ma << endl;
        if (ma < mi) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << mi << " " << ma << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}