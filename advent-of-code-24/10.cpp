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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

int T, N;
int a[50][50];
int dp[50][50];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool in (int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // N = 8;
    N = 45;
    rep(i,0,N) {
        string s; cin >> s;
        rep(j,0,N) {
            a[i][j] = s[j]-'0';
            if (a[i][j] == 9) dp[i][j] = 1;
        }
    }
    rrep(k,9,0) {
        rep(i,0,N) {
            rep(j,0,N) {
                if (a[i][j] != k) continue;
                rep(d,0,4) {
                    int ni = i+dx[d];
                    int nj = j+dy[d];
                    if (in(ni,nj) && a[ni][nj] == k-1) {
                        dp[ni][nj] += dp[i][j];
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,0,N) {
        rep(j,0,N) {
            if (a[i][j] == 0) ans += dp[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}