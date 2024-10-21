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

struct mat {
    vt<vt<int>> a;
    mat(int n, int m) {
        a = vt<vt<int>>(n, vt<int>(m));
    }
    mat operator*(const mat &b) const {
        mat c(a.size(), b.a[0].size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.a[0].size(); j++) {
                for (int k = 0; k < a[0].size(); k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k]*b.a[k][j]) % 37;
                }
            }
        }
        return c;
    }
};

int N;

int ctoi(char c) {
    if (c >= 'A' && c <= 'Z') return c-'A';
    else if (c >= '0' && c <= '9') return c-'0'+26;
    else return 36;
}

int itoc(int i) {
    if (i < 26) return 'A'+i;
    else if (i < 36) return '0'+i-26;
    else return ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    mat m(N,N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m.a[i][j];
        }
    }
    string s;
    getline(cin, s);
    getline(cin, s);
    s += string((sz(s)+N-1)/N*N-sz(s), ' ');
    string ans = "";
    for (int i = 0; i < sz(s); i += N) {
        mat c(N,1);
        for (int j = 0; j < N; j++) {
            c.a[j][0] = ctoi(s[i+j]);
        }
        mat d = m*c;
        for (int j = 0; j < N; j++) {
            ans += itoc(d.a[j][0]);
        }
    }
    cout << ans << endl;
    return 0;
}