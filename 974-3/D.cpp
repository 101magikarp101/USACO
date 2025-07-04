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

int T, N, D, K;
pii a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> D >> K;
        for (int i = 0; i < K; i++) {
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a+K);
        int ans = -1, ans2 = 1e9;
        int idx = -1, idx2 = -1;
        mset<int> s;
        int r = -1;
        while (r+1 < K && a[r+1].x <= D) {
            r++;
            s.insert(a[r].y);
        }
        if (sz(s) > ans) {
            ans = sz(s);
            idx = 1;
        }
        if (sz(s) < ans2) {
            ans2 = sz(s);
            idx2 = 1;
        }
        for (int i = 2; i+D-1 <= N; i++) {
            while (!s.empty() && *s.begin() < i) {
                s.erase(s.begin());
            }
            while (r+1 < K && a[r+1].x <= D+i-1) {
                r++;
                s.insert(a[r].y);
            }
            if (sz(s) > ans) {
                ans = sz(s);
                idx = i;
            }
            if (sz(s) < ans2) {
                ans2 = sz(s);
                idx2 = i;
            }
        }
        // cout << "ans: " << ans << " ans2: " << ans2 << endl;
        cout << idx << " " << idx2 << endl;
    }
    return 0;
}