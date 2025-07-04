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
#define fi first
#define se second
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

struct state {
    int i, p, v; // index, prioritiy, value
    bool operator<(const state &a) const { return p < a.p; }
};

int T, N;
int a[200005][3];
state b[200005][3];
vt<set<state>> s(3, set<state>());

char conv(int x) {
    if (x == 0) return 'Q';
    if (x == 1) return 'K';
    return 'J';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();
    cin >> T;
    while (T--) {
        cin >> N;
        for (int j = 0; j < 3; j++) {
            for (int i = 1; i <= N; i++) {
                cin >> a[i][j];
                b[i][j] = {-1, -1, -1};
            }
        }
        for (int j = 0; j < 3; j++) {
            s[j].clear();
            s[j].insert({j, a[1][j], 1});
        }
        vt<state> v(3, {-1, -1, -1});
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 3; j++) {
                v[j] = {-1, -1, -1};
            }
            for (int j = 0; j < 3; j++) {
                auto it = s[j].lower_bound({0, a[i][j], 0});
                auto it2 = lower_bound(all(s[j]), state{0, a[i][j], 0});
                if (it != s[j].end()) {
                    state cur = *it;
                    v[j] = cur;
                    b[i][j] = {cur.i, -1, cur.v};
                }
            }
            for (int j = 0; j < 3; j++) {
                if (v[j].i != -1) {
                    for (int k = 0; k < 3; k++) {
                        s[k].insert({j, a[i][k], i});
                    }
                }
            }
        }
        vt<state> path;
        for (int j = 0; j < 3; j++) {
            if (b[N][j].i != -1) {
                int i = N, p = j;
                while (i != -1) {
                    if (i == 1) break;
                    path.pb({p, a[i][p], i});
                    state temp = b[i][p];
                    i = temp.v;
                    p = temp.i;
                    if (i == -1) break;
                }
                break;
            }
        }
        if (path.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            reverse(all(path));
            cout << sz(path) << endl;
            for (state &i : path) {
                cout << conv(i.i) << " " << i.v << endl;
            }
        }
    }
    return 0;
}