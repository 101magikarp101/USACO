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

ll N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string s = to_string(N);
    int n = sz(s);
    vt<bool> used(10,0);
    for (int i = 0; i < n; i++) {
        used[s[i]-'0'] = 1;
    }
    vt<int> no;
    for (int i = 0; i < 10; i++) {
        if (!used[i]) no.pb(i);
    }
    if (sz(no) == 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    vt<ll> ans;
    ll dist = 1e18;
    int best = -1;
    for (int i : no) {
        if (i < s[0]-'0') {
            best = max(best,i);
        }
    }
    if (best != -1) {
        string t = to_string(best)+string(n-1,no[sz(no)-1]+'0');
        ll temp = stoll(t);
        ans.pb(temp);
        dist = abs(N-temp);
    } else {
        string t = string(n-1,no[sz(no)-1]+'0');
        ll temp = stoll(t);
        ans.pb(temp);
        dist = abs(N-temp);
    }
    best = 10;
    for (int i : no) {
        if (i > s[0]-'0') {
            best = min(best,i);
        }
    }
    if (best != 10) {
        string t = to_string(best)+string(n-1,no[0]+'0');
        ll temp = stoll(t);
        if (temp != 0) {
            if (abs(N-temp) < dist) {
                ans.clear();
                ans.pb(temp);
            } else if (abs(N-temp) == dist) {
                ans.pb(temp);
            }
        }
    } else {
        string t = to_string((no[0]==0&&sz(no)>1?no[1]:no[0]))+string(n,no[0]+'0');
        ll temp = stoll(t);
        if (temp != 0) {
            if (abs(N-temp) < dist) {
                ans.clear();
                ans.pb(temp);
            } else if (abs(N-temp) == dist) {
                ans.pb(temp);
            }
        }
    }
    if (sz(ans) == 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (ll i : ans) {
        cout << i << " ";
    }
    return 0;
}