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

int N, M;
ll P;
double dp[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> P;
    dp[N-1][M-1] = 0;
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            if (i == N-1 && j == M-1) continue;
            if (i != N-1 && j != M-1) {
                double diff = min((double)P, abs(dp[i+1][j] - dp[i][j+1]));
                double res = (diff*diff/2+(P-diff)*diff)/P/2;
                res += min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = res;
            } else if (i != N-1) {
                dp[i][j] = dp[i+1][j] + P/4.0;
            } else {
                dp[i][j] = dp[i][j+1] + P/4.0;
            }
        }
    }
    cout << fixed << setprecision(10);
    // rep(i,0,N) {
    //     rep(j,0,M) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][0] << endl;
    return 0;
}