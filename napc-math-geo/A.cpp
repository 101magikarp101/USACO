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

//AC

ll T, B;
vt<pii> pts[2][2];
int P = 1999;

ll c3(ll n) {
    return n*(n-1)*(n-2)/6;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < P; i++) {
        int x = i, y = i*i%P;
        pts[x%2][y%2].pb({x-1000, y-1000});
    }
    cin >> T >> B;
    ll c = c3(T);
    ll w = -1, x = -1, y = -1, z = -1;
    for (ll i = 0; i <= T; i++) {
        for (ll j = 0; j+i <= T && j<=i; j++) {
            for (ll k = 0; i+j+k <= T && k<=j; k++) {
                ll l = T-i-j-k;
                if (l > k) continue;
                ll res = c-i*j*k-j*k*l-i*k*l-i*j*l;
                if (res == B) {
                    w = i;
                    x = j;
                    y = k;
                    z = l;
                    break;
                }
            }
        }
    }
    if (w == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < w; i++) {
        cout << pts[0][0][i].x << " " << pts[0][0][i].y << endl;
    }
    for (int i = 0; i < x; i++) {
        cout << pts[1][0][i].x << " " << pts[1][0][i].y << endl;
    }
    for (int i = 0; i < y; i++) {
        cout << pts[0][1][i].x << " " << pts[0][1][i].y << endl;
    }
    for (int i = 0; i < z; i++) {
        cout << pts[1][1][i].x << " " << pts[1][1][i].y << endl;
    }
    return 0;
}