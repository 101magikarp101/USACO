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

ll N;
vt<ll> primes;
bool p[1000005];

void sieve(ll n) {
    p[0] = p[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (!p[i]) {
            primes.pb(i);
            for (ll j = i+i; j <= n; j += i) {
                p[j] = 1;
            }
        }
    }
}

bool sq(ll n) {
    ll x = sqrt(n);
    return x*x == n;
}

pll solve(ll n) {
    for (ll i = 0; i*i <= n; i++) {
        ll y = n-i*i;
        if (sq(y)) {
            return {i, (ll)sqrtl(y)};
        }
    }
    return {-1, -1};
}

bool good(ll n) {
    if (n <= 2) return 1;
    for (ll &x : primes) {
        if (x*x > n) break;
        if (n%x==0) {
            if (x==2 || x%4==1) {
                while (n%x==0) {
                    n /= x;
                }
            } else {
                int cnt = 0;
                while (n%x==0) {
                    n /= x;
                    cnt++;
                }
                if (cnt%2) return 0;
            }
        }
    }
    return n%4==1;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int cnt = 0;
    while (N%4==0) {
        N /= 4;
        cnt++;
    }
    if (N%8==7) {
        cout << -1 << endl;
        return 0;
    }
    sieve(1000000);
    vt<ll> v;
    for (ll i = 0; i*i <= N; i++) {
        v.pb(i);
    }
    shuffle(all(v), mt19937(chrono::steady_clock::now().time_since_epoch().count()));
    each(i,v) {
        ll y = N-i*i;
        if (!good(y)) continue;
        pll res = solve(y);
        ll hm = 1LL << cnt;
        cout << i*hm << " " << res.x*hm << " " << res.y*hm << endl;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end-start;
        cerr << "Time: " << elapsed.count() << endl;
        return 0;
    }
    return 0;
}