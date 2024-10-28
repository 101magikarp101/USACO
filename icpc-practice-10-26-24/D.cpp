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

string s, t;
deque<ll> a, b;
umap<ll,ll> ls, rs;
umap<ll,ll> h;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(LLONG_MIN, LLONG_MAX);

ll rev(ll x) {
    ll y = 0;
    for (int i = 0; i<64; i++) {
        y <<= 1;
        y |= x&1;
        x >>= 1;
    }
    return y;
}

ll hsh(ll x, ll y) {
    if (!h.count(x)) h[x] = dis(gen);
    if (!h.count(y)) h[y] = dis(gen);
    return rev(h[x])^h[y];
}

void solve(deque<ll> &a, string &s) {
    for (char &c : s) {
        if (c == 'C') {
            a.push_front(a.front());
        } else if (c == 'D') {
            a.pop_front();
        } else if (c == 'L') {
            ll x = a.front();
            a.pop_front();
            if (!ls.count(x)) {
                a.clear();
                return;
            } else {
                a.push_front(ls[x]);
            }
        } else if (c == 'R') {
            ll x = a.front();
            a.pop_front();
            if (!rs.count(x)) {
                a.clear();
                return;
            } else {
                a.push_front(rs[x]);
            }
        } else if (c == 'P') {
            ll x = a.front();
            a.pop_front();
            ll y = a.front();
            a.pop_front();
            ll z = hsh(x, y);
            ls[z] = x;
            rs[z] = y;
            a.push_front(z);
        } else if (c == 'S') {
            ll x = a.front();
            a.pop_front();
            ll y = a.front();
            a.pop_front();
            a.push_front(x);
            a.push_front(y);
        } else if (c == 'U') {
            ll z = a.front();
            a.pop_front();
            if (!ls.count(z) || !rs.count(z)) {
                a.clear();
                return;
            } else {
                a.push_front(rs[z]);
                a.push_front(ls[z]);
            }
        }
    }
}

bool same() {
    if (sz(a) != sz(b)) return 0;
    while (!a.empty() && !b.empty() && a.front() == b.front()) {
        a.pop_front();
        b.pop_front();
    }
    return a.empty() && b.empty();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    for (int i = 0; i<sz(s); i++) {
        ll x = dis(gen);
        a.pb(x);
        b.pb(x);
    }
    solve(a, s);
    solve(b, t);
    cout << (same() ? "True" : "False") << endl;
    return 0;
}