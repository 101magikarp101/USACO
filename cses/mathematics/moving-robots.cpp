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

int K;
double dp[8][8][8][8][101];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool in(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void precalc(int x, int y) {
    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (in(ni, nj)) {
                        cnt++;
                    }
                }
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (in(ni, nj)) {
                        dp[x][y][ni][nj][k] += dp[x][y][i][j][k-1]/cnt;
                    }
                }
            }
        }
    }
}

void precalc() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dp[i][j][i][j][0] = 1;
            precalc(i, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    precalc();
    double ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            double cur = 1;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    cur *= 1-dp[x][y][i][j][K];
                }
            }
            ans += cur;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}