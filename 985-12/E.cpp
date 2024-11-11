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

int T, N;
vt<int> primes;
bool p[400005];
int a[400005];

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

int ad(int a, int b, int M) {
    return (a+b)%M;
}

int sub(int a, int b, int M) {
    return (a-b+M)%M;
}

int mul(int a, int b, int M) {
    return (int)((a*1LL*b)%(1LL*M));
}

int binpow(int a, int b, int M) {
    int res = 1;
    while (b > 0) {
        if (b&1) {
            res = mul(res, a, M);
        }
        a = mul(a, a, M);
        b >>= 1;
    }
    return res;
}

int inv(int a, int M) {
    return binpow(a, M-2, M);
}

void factors(int x, vt<int> &fac) {
    for (auto p : primes) {
        if (p*p > x) {
            break;
        }
        if (x%p == 0) {
            fac.pb(p);
            while (x%p == 0) {
                x /= p;
            }
        }
    }
    if (x > 1) {
        fac.pb(x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(400000);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N);
        int pr = -1;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (!p[a[i]]) {
                if (pr == -1) {
                    pr = i;
                }
                cnt++;
            }
        }
        if (cnt == 0) {
            cout << 2 << endl;
            continue;
        } else if (pr != 0) {
            cout << -1 << endl;
            continue;
        }
        int x = 2*a[pr];
        bool ok = 1;
        for (int i = 1; i < N; i++) {
            bool g = 0;
            vt<int> fac;
            factors(a[i], fac);
            for (auto p : fac) {
                int y = ((-x)%p+p)%p;
                y = mul(y, inv(2, p), p);
                int res = y*2+x;
                // cout << "p: " << p << " res: " << res << " y: " << y << " x: " << x << endl;
                if (res <= a[i]) {
                    g = 1;
                    break;
                }
            }
            if (!g) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << a[pr] << endl;
        } else {
            cout << -1 << endl;
        }
    }    
    return 0;
}