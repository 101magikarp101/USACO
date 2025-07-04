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

int N, Q;
int hm[200005];
ll a[200005];
ll b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    hm[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        int cnt = 1;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) {
                cnt+=hm[i/j];
                if (j*j != i) cnt+=hm[j];
            }
        }
        hm[i] = -cnt;
    }
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        b[i] += a[i];
        for (int j = 1; j*j <= i; j++) {
            if (i==j) continue;
            if (i%j == 0) {
                b[j] += hm[i/j]*a[i];
                if (j*j != i && j!=1) b[i/j] += hm[j]*a[i];
            }
        }
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            ll d = y-a[x];
            a[x] += d;
            b[x] += d;
            for (int j = 1; j*j <= x; j++) {
                if (x==j) continue;
                if (x%j == 0) {
                    b[j] += hm[x/j]*d;
                    if (j*j != x && j!=1) b[x/j] += hm[j]*d;
                }
            }
        } else {
            int x; cin >> x;
            cout << b[x] << endl;
        }
    }
    return 0;
}