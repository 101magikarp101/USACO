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
int a[200005];
int p[200005];
vt<int> primes;

void sieve(int n) {
    p[0] = p[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) {
            primes.pb(i);
            for (int j = i+i; j <= n; j += i) {
                p[j] = 1;
            }
        }
    }
}

// bool semi(int x) {
//     if (!p[x]) return 0;
//     for (int pr : primes) {
//         if (pr >= x) break;
//         if (x % pr == 0 && !p[x/pr]) return 1;
//     }
//     return 0;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    sieve(200000);
    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,0,N) cin >> a[i];
        vt<int> b;
        vt<bool> sem(N, 0);
        ll ans = sz(b);
        map<int,ll> cnt, pcnt, tcnt;
        ll ps = 0;
        ll o = 0;
        rep(i,0,N) {
            if (a[i] == 1) {
                o++;
            } else if (!p[a[i]]) {
                b.pb(a[i]);
                pcnt[a[i]]++;
                ps++;
            } else {
                int x = -1, y = -1;
                for (int pr : primes) {
                    if (pr >= a[i]) break;
                    if (a[i] % pr == 0 && !p[a[i]/pr]) {
                        x = pr;
                        y = a[i]/pr;
                        break;
                    }
                }
                if (x == -1) continue;
                cnt[x]++;
                if (x!=y) cnt[y]++;
                tcnt[a[i]]++;
                sem[i] = 1;
            }
        }
        rep(i,0,N) {
            if (!p[a[i]]) {
                ans += (ps-pcnt[a[i]]);
            } else if (sem[i]) {
                ans += tcnt[a[i]]-1;
            }
        }
        ans /= 2;
        rep(i,0,N) {
            if (sem[i]) {
                ans++;
                ans += o;
            } else if (!p[a[i]]) {
                ans += cnt[a[i]];
            }
        }
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}