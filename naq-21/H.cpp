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

struct imp {
    vt<int> p;
    bool land;
    int q;
};

int T, N;
vt<imp> a;
bool used[600005];
umap<string,int> names;
int idx = 0;

bool eval(imp x) {
    if (x.land) {
        bool good = 1;
        for (int i : x.p) {
            if (!used[i]) {
                good = 0;
                break;
            }
        }
        if (good) {
            used[x.q] = 1;
            return 1;
        } else {
            return 0;
        }
    } else {
        bool good = 0;
        for (int i : x.p) {
            if (used[i]) {
                good = 1;
                break;
            }
        }
        if (good) {
            used[x.q] = 1;
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s != "if") {
            if (!names.count(s)) {
                used[idx] = 1;
                names[s] = idx++;
            } else {
                used[names[s]] = 1;
            }
        } else {
            imp x;
            x.land = 1;
            while (1) {
                string t; cin >> t;
                if (t == "then") {
                    break;
                }
                if (t != "and" && t != "or") {
                    if (!names.count(t)) {
                        names[t] = idx++;
                    }
                    x.p.pb(names[t]);
                } else if (t == "or") {
                    x.land = 0;
                }
            }
            string t; cin >> t;
            if (!names.count(t)) {
                names[t] = idx++;
            }
            x.q = names[t];
            a.pb(x);
        }
    }
    bool done = 0;
    while (!done) {
        done = 1;
        for (int i = 0; i < sz(a); i++) {
            bool res = eval(a[i]);
            // cout << "eval " << a[i].q << " " << res << endl;
            if (res) {
                done = 0;
                swap(a[i],a.back());
                a.pop_back();
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < idx; i++) {
        if (used[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}