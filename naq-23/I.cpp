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

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s; cin >> s;
        N = sz(s);
        vt<int> ans;
        for (int l = 1; l <= min(5,N); l++) {
            bool found = 0;
            bool good = 1;
            int tar = stoi(s.substr(0, l));
            int L = l;
            int res = -1;
            int first = tar;
            int last = -1;
            for (int i = 0; i < N;) {
                if (stoi(s.substr(i, L)) == tar) {
                    i += L;
                    last = tar;
                    tar++;
                    L = to_string(tar).size();
                } else if (!found) {
                    found = 1;
                    res = tar;
                    tar++;
                    L = to_string(tar).size();
                    // cout << "res: " << res << endl;
                } else {
                    found = 0;
                    good = 0;
                    // cout << "bad" << endl;
                    break;
                }
            }
            if (!good) continue;
            if (found) {
                ans.pb(res);
                continue;
            }
            if (last+1 < 100000) {
                ans.pb(last+1);
            }
            if (first != 1) {
                ans.pb(first-1);
            }
        }
        sort(all(s), [](int x, int y) {
            return x < y;
        });
        cout << sz(ans) << endl;
        for (int x:ans) {
            cout << x << endl;
        }
    }
    return 0;
}