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

int N;
string d = "ACGT";

int conv(char c) {
    if (c=='A') return 0;
    if (c=='C') return 1;
    if (c=='G') return 2;
    return 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int cur = 0;
    int tot = 0;
    string ans = "";
    for (int i = 0; i < sz(s); i++) {
        cur |= 1<<conv(s[i]);
        if (cur == 15) {
            tot++;
            cur = 0;
            ans += s[i];
        }
    }
    if (cur == 0) {
        cout << ans + "A" << endl;
    } else {
        cout << ans;
        for (int i = 0; i < 4; i++) {
            if (!(cur&(1<<i))) {
                cout << d[i];
                break;
            }
        }
        cout << endl;
    }
    return 0;
}