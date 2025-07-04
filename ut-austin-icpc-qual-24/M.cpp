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

ll T, N, C;
ll a[200005];

bool solve(ll x) {
    ll cur = 0;
    ll cnt = 1;
    for (ll i = 0; i < N; i++) {
        if (cur+a[i] > x*T) {
            cur = a[i];
            cnt++;
            if (cur > x*T) return 0;
        } else {
            cur += a[i];
        }
    }
    return cnt <= C;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C >> T;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll l = 1, r = 1e15;
    while (l < r) {
        ll m = (l+r)/2;
        if (solve(m)) {
            r = m;
        } else {
            l = m+1;
        }
    }
    cout << l << endl;
    return 0;
}