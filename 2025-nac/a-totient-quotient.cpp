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

int p[10005];
vt<int> primes;

void sieve(int n) {
    p[0] = p[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) {
            primes.pb(i);
            for (int j = i*i; j <= n; j += i) {
                p[j] = 1;
            }
        }
    }
}

void add(ll x, vt<int>& num, vt<int>& den) {
    for (int i = 0; i < sz(primes); i++) {
        int p = primes[i];
        while (x % p == 0) {
            num[i]++;
            x /= p;
        }
        int y = min(num[i], den[i]);
        num[i] -= y;
        den[i] -= y;
        if (x == 1) break;
    }
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b){
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    sieve(10000);
    int n = sz(primes);

    vt<int> num(n), den(n);

    int A, B; cin >> A >> B;
    rep(i,0,n) {
        int p = primes[i];
        while (A % p == 0) {
            num[i]++;
            A /= p;
        }
        while (B % p == 0) {
            den[i]++;
            B /= p;
        }
        int x = min(num[i], den[i]);
        num[i] -= x;
        den[i] -= x;
    }
    // cout << "num: ";
    // each(x, num) cout << x << " ";
    // cout << endl << "den: ";
    // each(x, den) cout << x << " ";
    // cout << endl;
    ll x = 1, y = 1;
    rrep(i,n-1,0) {
        if (num[i] == 0 && den[i] == 0) continue;
        // cout << "i: " << i << ", num[i]: " << num[i] << ", den[i]: " << den[i] << endl;
        // cout << "primes[i]: " << primes[i] << endl;
        if (num[i] > 0) {
            if (num[i]%2) {
                add(primes[i]-1, den, num);
            } else {
                y *= primes[i];
            }
            x *= binpow(primes[i], num[i]/2+1);
        } else if (den[i] > 0) {
            if (den[i]%2) {
                add(primes[i]-1, num, den);
            } else {
                x *= primes[i];
            }
            y *= binpow(primes[i], den[i]/2+1);
        }
        // cout << "x: " << x << ", y: " << y << endl;
    }
    cout << x << " " << y << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}