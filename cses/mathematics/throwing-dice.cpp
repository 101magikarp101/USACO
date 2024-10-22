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

struct mat {
    vt<vt<int>> a;
    mat(int n, int m) {
        a = vt<vt<int>>(n, vt<int>(m, 0));
    }
    mat operator* (const mat &b) {
        mat c(sz(a), sz(b.a[0]));
        for (int i = 0; i < sz(a); i++) {
            for (int j = 0; j < sz(b.a[0]); j++) {
                for (int k = 0; k < sz(b.a); k++) {
                    c.a[i][j] = ad(c.a[i][j], mul(a[i][k], b.a[k][j]));
                }
            }
        }
        return c;
    }
};

ll K;

mat binpow(mat a, ll b) {
    mat res(sz(a.a), sz(a.a));
    for (int i = 0; i < sz(a.a); i++) {
        res.a[i][i] = 1;
    }
    while (b) {
        if (b&1) res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s = 6;
    mat a(s,s);
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            int d = s-1-i-j;
            if (d >= 0) a.a[i][j] = binpow(2, d);
            else if (d == -1) a.a[i][j] = 1;
        }
    }
    mat b(s,s);
    for (int i = 0; i < s; i++) {
        b.a[i][0] = 1;
    }
    for (int j = 0; j < s-1; j++) {
        b.a[j][j+1] = 1;
    }
    cin >> K;
    mat res = binpow(b, K-1);
    a = a*res;
    cout << a.a[s-1][0] << endl;
    return 0;
}