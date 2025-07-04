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

ll ad(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

template <class T> class BIT {
public:
    vector<T> a;
    vector<T> c;
    ll size;

    BIT(ll n) {
        size = n;
        a = vector<T>(n + 1, 0);
        c = vector<T>(n + 1, 0);
    }

    // void add(ll i, T x) {
    //     a[i] += x;
    //     for (ll k = i; k <= size; k += k & -k) {
    //         bit[k] += x;
    //     }
    // }

    void set(ll x, T v, T cnt) {
        for (; x <= size; x += x & -x) {
            if (v > a[x]) {
                a[x] = v;
                c[x] = cnt;
            } else if (v == a[x]) {
                c[x] = ad(c[x], cnt);
            }
        }
    }

    pll query(ll x) {
        ll v = 0, cnt = 0;
        for (; x > 0; x -= x & -x) {
            if (a[x] > v) {
                v = a[x];
                cnt = c[x];
            } else if (a[x] == v) {
                cnt = ad(cnt, c[x]);
            }
        }
        return {v, cnt};
    }
};

ll N;
ll a[100005];
vt<ll> b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    b.resize(N);
    int bo; cin >> bo;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    BIT<ll> bit(N);
    ll lis = 0;
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int x = it-b.begin()+1;
        pll p = bit.query(x-1);
        bit.set(x, p.x+1, max(p.y, 1LL));
        if (p.x+1 > lis) {
            lis = p.x+1;
            cnt = p.y;
        } else if (p.x+1 == lis) {
            cnt = ad(cnt, p.y);
        }
    }
    cout << lis << endl;
    if (bo) {
        cout << cnt << endl;
    }
    return 0;
}