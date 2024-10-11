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

int ad(int a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD2;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD2);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD2-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int N, M;
int a[100005];
pll lines[100005];
vt<pll> c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);
    for (int i = 0; i < M; i++) {
        cin >> lines[i].x >> lines[i].y;
    }
    sort(lines, lines+M);
    for (int i = 0; i < M; i++) {
        if (i > 0 && lines[i].x == lines[i-1].x) continue;
        if (sz(c) <= 0) {
            c.pb(lines[i]);
            continue;
        }
        while (sz(c) >= 2) {
            pll a = c[sz(c)-2], b = c[sz(c)-1];
            pll d = lines[i];
            if ((b.y-d.y)*(d.x-a.x) >= (a.y-d.y)*(d.x-b.x)) {
                c.pop_back();
            } else {
                break;
            }
        }
        c.pb(lines[i]);
    }
    int cur = sz(c)-1;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        while (cur > 0) {
            pll x = c[cur-1], y = c[cur];
            if (x.x*(ll)a[i]+x.y <= y.x*(ll)a[i]+y.y) {
                cur--;
            } else {
                break;
            }
        }
        ans = ad(ans, ad(mul(a[i], c[cur].x), c[cur].y));
    }
    cout << ans << endl;
    return 0;
}