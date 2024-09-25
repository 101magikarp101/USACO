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
set<int> adj[100005];
int b[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < N-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        for (int i = 1; i <= N; i++) {
            cin >> b[i];
        }
        bool good = 1;
        for (int i = 1; i <= N; i++) {
            int x = b[i];
            if (adj[x].size() == 1) {
                int v = *adj[x].begin();
                adj[v].erase(x);
                adj[x].clear();
            } else if (adj[x].size() > 1) {
                good = 0;
                break;
            }
        }
        if (!good) {
            cout << 2 << endl;
            for (int i = N; i >= 1; i--) {
                cout << b[i] << " ";
            }
            cout << endl;
            for (int i = 1; i <= N; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
        } else {
            cout << 1 << endl;
            for (int i = 1; i <= N; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}