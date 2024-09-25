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

int T, L, N, M;
int a[1505];
int b[1505][1505];
int ind[3000005];
int dp0[1505][1505], dp1[1505][1505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> L >> N >> M;
        for (int i = 0; i < L; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < L; i++) {
            if (ind[a[i]] != 0) {
                L = i;
                break;
            }
            ind[a[i]] = i+1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> b[i][j];
            }
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dp0[i][j] = dp1[i][j] = 1e9;
            }
        }
        for (int i = N-1; i >= 0; i--) {
            for (int j = M-1; j >= 0; j--) {
                dp0[i][j] = min(dp0[i+1][j], dp0[i][j+1]);
                dp1[i][j] = min(dp1[i+1][j], dp1[i][j+1]);
                if (ind[b[i][j]] == 0) {
                    continue;
                }
                if (ind[b[i][j]] % 2 == 1 && ind[b[i][j]]+1 < dp0[i+1][j+1]) {
                    dp1[i][j] = min(dp1[i][j], ind[b[i][j]]);
                }
                if (ind[b[i][j]] % 2 == 0 && ind[b[i][j]]+1 < dp1[i+1][j+1]) {
                    dp0[i][j] = min(dp0[i][j], ind[b[i][j]]);
                }
            }
        }
        // cout << "dp0" << endl;
        // for (int i = 0; i <= N; i++) {
        //     for (int j = 0; j <= M; j++) {
        //         cout << dp0[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "dp1" << endl;
        // for (int i = 0; i <= N; i++) {
        //     for (int j = 0; j <= M; j++) {
        //         cout << dp1[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << (dp1[0][0] == 1?"T":"N") << endl;
        for (int i = 0; i < L; i++) {
            ind[a[i]] = 0;
        }
    }
    return 0;
}