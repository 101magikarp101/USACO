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

int R, S, N;
int a[55], b[55];
int c[105];
int prea[55], preb[55];
int d[55][55][55][55];
bool can[2000005];
bool dp[105][55][55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> S >> N;
    for (int i = 0; i < R; i++) cin >> a[i];
    for (int i = 0; i < S; i++) cin >> b[i];
    for (int i = 1; i <= N; i++) cin >> c[i];
    prea[0] = a[0];
    for (int i = 1; i < R; i++) prea[i] = prea[i-1]+a[i];
    preb[0] = b[0];
    for (int i = 1; i < S; i++) preb[i] = preb[i-1]+b[i];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            for (int k = 0; k < R; k++) {
                for (int l = 0; l < S; l++) {
                    int s1 = (k>=i?prea[k]-prea[i]:prea[R-1]-prea[i]+prea[k]);
                    int s2 = (l>=j?preb[l]-preb[j]:preb[S-1]-preb[j]+preb[l]);
                    int dist = s1+s2;
                    d[i][j][k][l] = dist;
                }
            }
        }
    }
    can[0] = 1;
    int ppa = prea[R-1];
    int ppb = preb[S-1];
    for (int i = 1; i <= 2000000; i++) {
        if (i-ppa >= 0) can[i] |= can[i-ppa];
        if (i-ppb >= 0) can[i] |= can[i-ppb];
    }
    dp[0][R-1][S-1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < S; k++) {
                if (!dp[i-1][j][k]) continue;
                for (int l = 0; l < R; l++) {
                    for (int m = 0; m < S; m++) {
                        int rest = c[i]-d[j][k][l][m];
                        if (rest < 0) continue;
                        if (can[rest]) dp[i][l][m] = 1;
                    }
                }
            }
        }
    }
    bool ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (dp[N][i][j]) ans = 1;
        }
    }
    cout << (ans?"yes":"no") << endl;
    return 0;
}