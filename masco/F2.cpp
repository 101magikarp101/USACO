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

int r = 2, c = 10;
vt<vt<int>> v;
ll cnt = 0;

bool check(int n) {
    int x = n % r, y = n / r;
    for (int i = x-1; i >= 0; i--) {
        for (int j = y-1; j >= 0; j--) {
            int a = v[i][j], b = v[i][y], c = v[x][j], d = v[x][y];
            if (a == b && b == c && c == d) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int n) {
    int x = n % r, y = n / r;
    v[x][y] = 1;
    cnt++;
    if (n == r*c-1) {
        if (check(n)) {
            return true;
        }
    } else if (check(n)) {
        bool res = solve(n+1);
        if (res) {
            return true;
        }
    }
    v[x][y] = 2;
    cnt++;
    if (n == r*c-1) {
        if (check(n)) {
            return true;
        }
    } else if (check(n)) {
        bool res = solve(n+1);
        if (res) {
            return true;
        }
    }
    v[x][y] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    v = vt<vt<int>>(r, vt<int>(c, 0));
    solve(0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}