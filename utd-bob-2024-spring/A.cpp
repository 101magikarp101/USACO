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

ll B, H, vv, hh;
ll h[200005], v[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> B >> H >> vv >> hh;
    for (int i = 0; i < vv; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < hh; i++) {
        cin >> h[i];
    }
    sort(v, v+vv);
    sort(h, h+hh);
    ll ans = hh+1;
    ll r = -1;
    for (int i = 0; i < vv; i++) {
        if (v[i] >= 0) {
            if (v[i] == 0) {
                ans += 2*(hh+1);
            }
            break;
        }
        while (r+1 < hh && B*(H-h[r+1]) > -2*H*v[i]) {
            r++;
        }
        // cout << "i: " << i << " r: " << r << endl;
        ans += r+2;
    }
    // cout << "ans1: " << ans << endl;
    r = -1;
    for (int i = vv-1; i >= 0; i--) {
        if (v[i] <= 0) break;
        while (r+1 < hh && B*(H-h[r+1]) > 2*H*v[i]) {
            r++;
        }
        // cout << "i: " << i << " r: " << r << endl;
        ans += r+2;
    }
    cout << ans << endl;
    return 0;
}