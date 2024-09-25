#include "nile.h"
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

struct info {
    ll w, x, y;
    bool operator<(const info &x) const { return w < x.w; }
};

vt<ll> calculate_costs(vt<int> W, vt<int> A, vt<int> B, vt<int> E) {
    int N = W.size();
    vt<info> a(N);
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        a[i].w = W[i];
        a[i].x = A[i];
        a[i].y = B[i];
        tot += (ll)A[i];
        a[i].x -= B[i];
    }
    sort(all(a));
    // cout << "a: " << endl;
    vt<ll> ans;
    vt<ll> dp(N+1);
    for (ll D : E) {
        // cout << "D: " << D << endl;
        for (int i = 0; i <= N; i++) dp[i] = -1e18;
        dp[0] = 0;
        mset<pll> s;
        mset<ll> s2;
        for (int i = 0; i < N; i++) {
            dp[i+1] = max(dp[i+1], dp[i]);
            while (!s.empty() && s.begin()->x < a[i].w - D) {
                s2.erase(s2.find(s.begin()->y));
                s.erase(s.begin());
            }
            ll hm = a[i].x + dp[i];
            // cout << "hm: " << hm << endl;
            dp[i+1] = max(dp[i+1], s2.empty() ? (ll)-1e18 : *s2.rbegin() + a[i].x);
            s.insert({a[i].w, hm});
            s2.insert(hm);
        }
        ans.pb(tot-dp[N]);
    }
    return ans;
}