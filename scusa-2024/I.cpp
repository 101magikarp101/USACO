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

int N, M;
bitset<1000> a[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    bitset<1000> big;
    for (int i = 0; i < N; i++) {
        big[i] = 1;
    }
    for (int i = 0; i < M; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            a[i][x-1] = 1;
        }
        if (a[i][0]) {
            a[i] = big^a[i];
        }
    }
    bool ans = 1;
    for (int i = 0; i < M; i++) {
        bitset<1000> hm;
        for (int j = 0; j < M; j++) {
            if (a[i] == a[j]) {
                continue;
            }
            bitset<1000> b = a[i] & a[j];
            if (b == 0) continue;
            if (b != a[i] && b != a[j]) {
                ans = 0;
                break;
            }
            if (b == a[j]) hm |= a[j];
        }
        if (hm == a[i]) ans = 0;
        if (!ans) break;
    }
    cout << ans << endl;
    return 0;
}