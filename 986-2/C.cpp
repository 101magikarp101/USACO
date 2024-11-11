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

int T, N, M;
ll V;
int a[200005];

struct state {
    int l, r;
    ll s;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> V;
        ll tot = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            tot += a[i];
        }
        ll sum = 0;
        vt<state> v1, v2;
        ll cur = 0;
        int l = 0;
        for (int i = 0; i < N; i++) {
            cur += a[i];
            sum += a[i];
            if (cur >= V) {
                v1.pb({l, i, cur});
                l = i+1;
                cur = 0;
            }
            if (sz(v1) >= M) {
                break;
            }
        }
        if (sz(v1) < M) {
            cout << -1 << endl;
            continue;
        }
        ll ans = tot-sum;
        int r = N;
        for (int i = M-1; i >= 0; i--) {
            sum -= v1[i].s;
            ll cur = 0;
            v1.pop_back();
            for (int j = r-1; j >= 0; j--) {
                cur += a[j];
                sum += a[j];
                if (cur >= V) {
                    v2.pb({j, r-1, cur});
                    r = j;
                    cur = 0;
                }
                if (sz(v2) >= M-i) {
                    break;
                }
            }
            if (sz(v2) < M-i) {
                continue;
            }
            int left = (!v1.empty()?v1.back().r:-1);
            if (r > left) {
                ckmax(ans, tot-sum);
            }
        }
        cout << ans << endl;
    }
    return 0;
}