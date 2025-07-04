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

int T, N;
bool dp[1000005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        int s, k; cin >> s >> k;
        if (s%k==0) {
            cout << k << endl;
            continue;
        }
        if (s >= k*k && k > 2) {
            cout << k-2 << endl;
            continue;
        } else if (s >= k*k && k <= 2) {
            cout << 1 << endl;
            continue;
        }
        rep(i,0,s+1) dp[i][0] = dp[i][1] = 0;
        dp[0][0] = 1;
        bool found = 0;
        rrep(i,k,1) {
            if ((k-i)%2==0) {
                rep(j,i,s+1) {
                    dp[j][1] = dp[j-i][0] | dp[j-i][1];
                }
                rep(j,0,i) {
                    dp[j][1] = 0;
                }
            } else {
                rrep(j,s-i,0) {
                    dp[j][1] = dp[j+i][0] | dp[j+i][1];
                }
                rep(j,s-i+1,s+1) {
                    dp[j][1] = 0;
                }
            }
            rep(j,0,s+1) dp[j][0] = dp[j][1];
            if (dp[s][0]) {
                cout << i << endl;
                found = 1;
                break;
            }
            // cout << "i: " << i << endl;
            // rep(j,0,s+1) cout << dp[j][0] << " ";
            // cout << endl;
        }
        if (!found) cout << 1 << endl;
    }


    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}