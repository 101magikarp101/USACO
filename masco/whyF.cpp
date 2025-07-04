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

int T, N;
int r = 8, c = 10;
vt<vt<int>> v;

bool check() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = i+1; k < r; k++) {
                for (int l = j+1; l < c; l++) {
                    int a = v[i][j], b = v[i][l], c = v[k][j], d = v[k][l];
                    if (a == b && b == c && c == d) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

string base3(ll x) {
    string s = "";
    for (int i = 0; i < r+c-1; i++) {
        s += (char)('0' + x % 3);
        x /= 3;
    }
    return s;
}

bool construct(ll x) {
    v = vt<vt<int>>(r, vt<int>(c, 0));
    string s = base3(x);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int k = i+j;
            v[i][j] = s[k]-'0';
        }
    }
    return check();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 0; i < pow(3,r+c-1); i++) {
        bool res = construct(i);
        if (i % 1000000 == 0) {
            cout << i << endl;
            cout.flush();
        }
        if (res) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cout << v[j][k] << " ";
                }
                cout << endl;
            }
            break;
        }
    }
    return 0;
}