#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
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

int T, N, K, Q;

int lt(int j, int x, vt<vt<ll>> &a) {
    if (a[0][j] >= x) return -1;
    int l = 0, r = N-1;
    while (l < r) {
        int m = (l+r+1)/2;
        if (a[m][j] < x) {
            l = m;
        } else {
            r = m-1;
        }
    }
    return l;
}

int gt(int j, int x, vt<vt<ll>> &a) {
    if (a[N-1][j] <= x) return N;
    int l = 0, r = N-1;
    while (l < r) {
        int m = (l+r)/2;
        if (a[m][j] > x) {
            r = m;
        } else {
            l = m+1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> Q;
    vt<vt<ll>> a(N, vt<ll>(K,0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < K; j++) {
        for (int i = 1; i < N; i++) {
            a[i][j] |= a[i-1][j];
        }
    }
    while (Q--) {
        int m; cin >> m;
        int l = 0, r = N-1;
        for (int i = 0; i < m; i++) {
            int x, y; char c; cin >> x >> c >> y;
            x--;
            if (c == '<') {
                ckmin(r, lt(x, y, a));
            } else {
                ckmax(l, gt(x, y, a));
            }
        }
        // cout << "l = " << l << " r = " << r << endl;
        cout << (l<=r?l+1:-1) << endl;
    }
    return 0;
}