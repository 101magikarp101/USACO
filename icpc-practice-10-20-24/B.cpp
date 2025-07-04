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

int N, M, K;
char a[11][11];
bool dp[11][11][101][8][101];
string s;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool search(int x, int y, int idx, int dir, int k) {
    if (dp[x][y][idx][dir][k]) return 0;
    if (k > K) return 0;
    if (idx == sz(s)-1) {
        if (k==-1) return K==0;
        else return k == K;
    }
    dp[x][y][idx][dir][k] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (in(nx, ny) && a[nx][ny] == s[idx+1]) {
            if (i != dir || k == -1) {
                if (search(nx, ny, idx+1, i, k+1)) return 1;
            } else {
                if (search(nx, ny, idx+1, i, k)) return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    cin >> K >> s;
    if (K >= sz(s)) {
        cout << "NO" << endl;
        return 0;
    }
    bool good = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != s[0]) continue;
            bool res = search(i, j, 0, 0, -1);
            // cout << "search " << i << " " << j << " " << res << endl;
            if (res) {
                good = 1;
                break;
            }
        }
        if (good) break;
    }
    cout << (good ? "YES" : "NO") << endl;
    return 0;
}