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

ll T, N;
ll sum;
ll a[200005];

bool solve(ll x) {
    a[N-1] += x;
    ll tot = sum+x;
    ll avg = (tot-1)/(2*N);
    // cout << "x: " << x << " avg: " << avg << endl;
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] <= avg) {
            cnt++;
        }
    }
    // cout << x << " " << cnt << " " << N << endl;
    a[N-1] -= x;
    return cnt >= (N+2)/2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            sum += a[i];
        }
        // cout << "N: " << N << " sum: " << sum << endl;
        sort(a, a+N);
        ll l = 0, r = 1e18;
        while (l < r) {
            ll m = (l+r)/2;
            if (solve(m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        cout << (l==1e18?-1:l) << endl;
    }
    return 0;
}