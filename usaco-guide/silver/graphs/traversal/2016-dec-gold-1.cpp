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

int N;
pii a[1005];
int d[1005][1005];
bool vis[1005];

bool solve(int x) {
    for (int i = 0; i < N; i++) vis[i] = 0;
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < N; v++) {
            if (d[u][v] <= x && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    bool good = 1;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            good = 0;
            break;
        }
    }
    return good;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // #ifdef ONLINE_JUDGE
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    // #endif
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int dx = a[i].x - a[j].x;
            int dy = a[i].y - a[j].y;
            d[i][j] = dx*dx + dy*dy;
        }
    }
    int l = 0, r = 13e8;
    while (l < r) {
        int m = (l+r)/2;
        if (solve(m)) {
            r = m;
        } else {
            l = m+1;
        }
    }
    cout << l << endl;
    return 0;
}