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

ll N;

ll solve1(ll n) {
    return (1LL<<n)*(n+1);
}

ll solve(int n, ll v) {
    int x = (v>>n)&1;
    if (n == 0) return x;
    if (x) {
        ll res = solve1(n-1);
        v ^= 1LL<<n;
        res += solve(n-1, v)+v+1;
        // cout << "n: " << n << " v: " << v << " res: " << res << endl;
        return res;
    } else {
        ll res = solve(n-1, v);
        // cout << "n: " << n << " v: " << v << " res: " << res << endl;
        return res;
    }
}

string to_bin(ll n) {
    string s = "";
    while (n) {
        s += to_string(n%2);
        n /= 2;
    }
    reverse(all(s));
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string s = to_bin(N);
    ll ans = solve(sz(s)-1, N);
    cout << ans << endl;
    return 0;
}