#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

int N, Q;
char a[1005][1005];
int dist[1005][1005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct state {
    int x, y, d;
    bool operator<(const state &s) const {
        return d > s.d;
    }
};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    vt<pii> e;
    rep(i,0,N) {
        string s; cin >> s;
        rep(j,0,N) {
            a[i][j] = s[j];
            if (s[j] == 'E') e.pb({i, j});
        }
    }
    priority_queue<state> pq;
    rep(i,0,N) rep(j,0,N) dist[i][j] = 1e9;
    each(i, e) {
        pq.push({i.x, i.y, 1});
        dist[i.x][i.y] = 1;
    }
    while (!pq.empty()) {
        state s = pq.top(); pq.pop();
        if (dist[s.x][s.y] < s.d) continue;
        rep(i,0,4) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            if (!in(nx, ny)) continue;
            if (a[nx][ny] == '#') continue;
            if (s.d + 1 < dist[nx][ny]) {
                dist[nx][ny] = s.d + 1;
                pq.push({nx, ny, s.d + 1});
            }
        }
    }
    int tot = 0;
    vt<int> ans(N*N+1);
    rep(i,0,N) rep(j,0,N) {
        if (a[i][j] == '#' || a[i][j] == 'E') continue;
        tot++;
        if (dist[i][j] < 1e9) ans[dist[i][j]]++;
    }
    rep(i,1,N*N+1) ans[i] += ans[i-1];
    cout << fixed << setprecision(10);
    while (Q--) {
        int x; cin >> x;
        cout << (double)ans[x] / tot << endl;
    }


    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}