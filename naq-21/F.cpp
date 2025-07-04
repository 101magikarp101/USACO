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

int N, C;
vt<int> a, b;
bool vis[100005];

string solve(vt<int> v) {
    vt<pii> segs;
    segs.pb({v[0],v[0]});
    for (int i = 1; i < sz(v); i++) {
        if (v[i] == segs.back().y+1) {
            segs.back().y = v[i];
        } else {
            segs.pb({v[i],v[i]});
        }
    }
    string ans = "";
    for (int i = 0; i < sz(segs); i++) {
        string t;
        if (segs[i].x == segs[i].y) {
            t = to_string(segs[i].x);
        } else {
            t = to_string(segs[i].x) + "-" + to_string(segs[i].y);
        }
        if (sz(segs)>=2) {
            if (i==sz(segs)-2) {
                t += " and ";
            } else if (i<sz(segs)-2) {
                t += ", ";
            }
        }
        ans += t;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        a.pb(x);
        vis[x] = 1;
    }
    for (int i = 1; i <= C; i++) {
        if (!vis[i]) b.pb(i);
    }
    cout << "Errors: " << solve(a) << endl;
    cout << "Correct: " << solve(b) << endl;
    return 0;
}