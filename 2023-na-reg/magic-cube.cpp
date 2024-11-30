#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

struct op {
    char c; int th, k;
};

int N, M;
vt<op> v;

int query(int x, int y, int z) {
    for (int i = sz(v)-1; i >= 0; i--) {
        if (v[i].c == 'x') {
            if (x >= v[i].k) {
                for (int j = 0; j < v[i].th; j+=90) {
                    int ny = N-z+1, nz = y;
                    y = ny, z = nz;
                }
            }
        } else if (v[i].c == 'y') {
            if (y >= v[i].k) {
                for (int j = 0; j < v[i].th; j+=90) {
                    int nx = z, nz = N-x+1;
                    x = nx, z = nz;
                }
            }
        } else {
            if (z >= v[i].k) {
                for (int j = 0; j < v[i].th; j+=90) {
                    int nx = N-y+1, ny = x;
                    x = nx, y = ny;
                }
            }
        }
        // cout << "x: " << x << " y: " << y << " z: " << z << endl;
    }
    return x+(y-1)*N+(z-1)*N*N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while (M--) {
        char c; cin >> c;
        if (c != 'q') {
            int th, k; cin >> th >> k;
            k++;
            v.pb({c, th, k});
        } else {
            int x, y, z; cin >> x >> y >> z;
            cout << query(x, y, z) << endl;
        }
    }
    return 0;
}