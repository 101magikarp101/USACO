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

int N, M;
vt<int> adj[100005];

ll c3(ll x) {
    return x*(x-1)*(x-2)/6;
}

int main() {
    // auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= N; i++) {
        sort(all(adj[i]));
    }
    ll ans = 0;
    ll cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (sz(adj[i])>=4) {
            ll k = 0, kk = 0;
            for (int j : adj[i]) {
                ll tempk = 0;
                int l = 0;
                for (int m = 0; m < sz(adj[j]); m++) {
                    cnt++;
                    if (adj[j][m] == i) continue;
                    while (l < sz(adj[i]) && adj[i][l] < adj[j][m]) {
                        l++;
                        if (l == sz(adj[i])) goto jump;
                    }
                    if (adj[i][l] == adj[j][m]) {
                        tempk++;
                    }
                }
                jump:
                k += tempk;
                kk += sz(adj[j])-1-tempk;
            }
            ans += c3(sz(adj[i])-2)*k;
            ans += c3(sz(adj[i])-1)*kk;
        }
    }
    // cout <<"cnt: " << cnt << endl;
    cout << ans << endl;
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
    // cerr << "Time: " << duration.count() << "ms" << endl;
    return 0;
}