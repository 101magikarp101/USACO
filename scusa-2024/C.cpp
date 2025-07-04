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

int N, D, C;
int a[200005];

bool solve1(int x) {
    int cur = 0;
    rep(i,0,N) {
        int d = x-a[i];
        cur -= d;
        if (cur < 0) cur = 0;
        if (cur > C) return 0;
    }
    return 1;
}

bool solve2(int x) {
    int cur = C;
    rep(i,0,N) {
        int d = x-a[i];
        cur -= d;
        if (cur > C) cur = C;
        if (cur < 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> D >> C;
    rep(i,0,N) cin >> a[i];
    int l = 0, r = D;
    while (l < r) {
        int m = (l+r+1)/2;
        if (solve2(m)) {
            l = m;
        } else {
            r = m-1;
        }
    }
    int mi = l;
    l = 0, r = D;
    while (l < r) {
        int m = (l+r)/2;
        if (solve1(m)) {
            r = m;
        } else {
            l = m+1;
        }
    }
    int ma = l;
    cout << "mi: " << mi << " ma: " << ma << endl;
    cout << max(0, ma-mi) << endl;
    return 0;
}