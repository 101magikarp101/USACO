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

int H, K, N;
pii a[205];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> H >> K >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
    }
    double ans = 0;
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= K; j++) {
            double res = 1e6;
            for (int k = 0; k < N; k++) {
                res = min(res, sqrt((i-a[k].x)*(i-a[k].x) + (j-a[k].y)*(j-a[k].y)));
            }
            res = min({res, (double)i, (double)j, (double)H-i, (double)K-j});
            ans = max(ans, res);
        }
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}