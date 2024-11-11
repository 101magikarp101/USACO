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

int T, N;
int a[300005];
int b[300005];
int c[300005];
int d[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            b[i] = 0;
            c[i] = 0;
            d[i] = 0;
        }
        int x = 0;
        for (int i = 1; i <= N; i++) {
            if (a[i] > x) {
                x++;
            } else if (a[i] < x) {
                x--;
            }
            b[i] = x;
        }
        for (int i = 1; i <= N; i++) {
            c[i] = max(c[i-1], b[i-1]);
        }
        for (int i = 2; i <= N; i++) {
            d[i] = max(d[i-1], c[i-1]);
            if (d[i] < a[i]) {
                d[i]++;
            } else if (d[i] > a[i]) {
                d[i]--;
            }
        }
        // cout << "a: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // cout << "b: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        // cout << "c: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << c[i] << " ";
        // }
        // cout << endl;
        // cout << "d: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << d[i] << " ";
        // }
        // cout << endl;
        cout << max(d[N], c[N]) << endl;
    }
    return 0;
}