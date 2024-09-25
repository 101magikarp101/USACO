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

int N, K, C;
pii a[100005];
bool used[100005];
map<int,int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> C;
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
    }
    vt<pii> v;
    for (int i = 0; i < N; i++) {
        if (m[a[i].y] < C && sz(v) < K) {
            m[a[i].y]++;
            used[i] = 1;
            v.pb({i, a[i].x});
        }
    }
    for (int i = 0; i < N; i++) {
        if (sz(v) < K) {
            if (!used[i]) {
                v.pb({i, a[i].x});
            }
        }
    }
    sort(all(v));
    for (pii x:v) {
        cout << x.y << endl;
    }
    return 0;
}