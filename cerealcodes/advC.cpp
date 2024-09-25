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
ll a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = -1;
        ll s = 0, s1 = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            s1 += a[i];
        }
        s1 -= a[1];
        s = a[0];
        int j = 1;
        while (j < N-1 && max(s,s1) > max(s+a[j],s1-a[j+1])) {
            s += a[j];
            s1 -= a[j+1];
            j++;
        }
        ans = max(ans, max(s,s1));
        for (int i = 1; i < N; i++) {
            s1 += a[i];
            s -= a[i-1];
            while (max(s,s1) > max(s+a[j],s1-a[(j+1)%N])) {
                s += a[j];
                s1 -= a[(j+1)%N];
                j = (j+1)%N;
            }
            // cout << "i: " << i << " j: " << j << " s: " << s << " s1: " << s1 << endl;
            ans = max(ans, max(s,s1));
        }
        cout << ans << endl;
    }
    return 0;
}