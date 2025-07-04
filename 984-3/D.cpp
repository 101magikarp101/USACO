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

int T, N, M;
int a[1005][1005];

int solve(vt<int> &v) {
    int n = sz(v);
    int ans = 0;
    for (int i = 0; i < sz(v); i++) {
        ans += (v[i]==1&&v[(i+1)%n]==5&&v[(i+2)%n]==4&&v[(i+3)%n]==3);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            for (int j = 0; j < M; j++) {
                a[i][j] = s[j]-'0';
            }
        }
        int ans = 0;
        for (int d = 0; d < min(N,M)/2; d++) {
            vt<int> v;
            for (int i = d; i < M-d; i++) {
                v.pb(a[d][i]);
            }
            for (int i = d+1; i < N-d; i++) {
                v.pb(a[i][M-d-1]);
            }
            for (int i = M-d-2; i >= d; i--) {
                v.pb(a[N-d-1][i]);
            }
            for (int i = N-d-2; i > d; i--) {
                v.pb(a[i][d]);
            }
            // cout << "d = " << d << " v = ";
            // for (int i = 0; i < sz(v); i++) {
            //     cout << v[i] << " ";
            // }
            // cout << endl;
            ans += solve(v);
            // cout << "d = " << d << " ans = " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}