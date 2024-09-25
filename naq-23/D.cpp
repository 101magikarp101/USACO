#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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

ll N, R, W, H;

ld seg(ld d) {
    if (d >= R) return 0;
    ld theta = 2*acos(d/R);
    ld tri = R*R*sin(theta)/2;
    ld sec = R*R*theta/2;
    // cout << "d: " << d << " theta: " << theta << " tri: " << tri << " sec: " << sec << endl;
    return sec-tri;
}

ld seg2(ld theta) {
    ld tri = R*R*sin(theta)/2;
    ld sec = R*R*theta/2;
    return sec-tri;
}

ld seg3(ld x, ld y) {
    ld ans = 0;
    if (R*R >= x*x+y*y) {
        ld theta = acos(y/R)-asin(x/R);
        ans += seg2(theta);
        ld xx = sqrt(R*R-y*y)-x;
        ld yy = sqrt(R*R-x*x)-y;
        ans += xx*yy/2;
    }
    // cout << "x: " << x << " y: " << y << " ans: " << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R >> W >> H;
    ld ans = 0;
    for (int i = 0; i < N; i++) {
        int x, y, v; cin >> x >> y >> v;
        ld a = R*R*M_PI;
        ld b = seg(x)+seg(W-x)+seg(y)+seg(H-y);
        ld c = seg3(x,y)+seg3(W-x,y)+seg3(x,H-y)+seg3(W-x,H-y);
        // cout << "a: " << a << " b: " << b << " c: " << c << endl;
        b -= c;
        a -= b;
        a *= v;
        a /= W*H;
        // cout << "a: " << a << endl;
        ans += a;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}