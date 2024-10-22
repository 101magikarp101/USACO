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

char a[8][8];
bool b[8][8];

bool in(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

bool good(int i, int j) {
    return in(i,j) && a[i][j] == '.';
}

bool valid(int x, int y) {
    for (int i = -1; i <= 1; i++) {
        int xx = x, yy = y;
        while (true) {
            xx--;
            yy+=i;
            if (!in(xx,yy)) break;
            if (b[xx][yy]) return 0;
        }
    }
    return 1;
}

ll dfs(int n) {
    if (n==8) return 1;
    ll res = 0;
    for (int i = 0; i < 8; i++) {
        if (!good(n,i)) continue;
        b[n][i] = 1;
        if (valid(n,i)) res += dfs(n+1);
        b[n][i] = 0;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 8; i++) {
        string s; cin >> s;
        for (int j = 0; j < 8; j++) {
            a[i][j] = s[j];
        }
    }
    ll ans = dfs(0);
    cout << ans << endl;
    return 0;
}