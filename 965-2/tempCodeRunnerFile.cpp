#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

template <class T> class BIT {
public:
    vector<T> bit;
    vector<T> a;
    ll size;

    BIT(ll n) {
        size = n;
        bit.resize(n + 1);
        a.resize(n + 1);
    }

    void add(ll i, T x) {
        a[i] += x;
        for (ll k = i; k <= size; k += k & -k) {
            bit[k] += x;
        }
    }

    void set(ll i, T x) {
        add(i, x - a[i]);
    }

    T sum(ll i) {
        if (i <= 0) return 0;
        if (i > size) i = size;
        T s = 0;
        for (ll k = i; k > 0; k -= k & -k) {
            s += bit[k];
        }
        return s;
    }
};

ll T, N, X;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        BIT<ll> bit(N);
        for (int i = 1; i <= N; i++) {
            ll v; cin >> v;
            bit.add(i, v);
        }
        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            ll x = bit.a[i];
            ll l = i, r = i;
            bool good = 0;
            while (l != 1 || r != N) {
                // cout << "l: " << l << " r: " << r << " x: " << x << endl;
                if (x >= X) {
                    good = 1;
                    break;
                }
                bool bad = 1;
                ll l_ = 1, r_ = l;
                while (l_ < r_) {
                    ll m = (l_+r_)/2;
                    if (bit.sum(l-1)-(m==1?0:bit.sum(m-1)) <= x) {
                        r_ = m;
                    } else {
                        l_ = m+1;
                    }
                }
                x += bit.sum(l-1)-(r_==1?0:bit.sum(r_-1));
                bad &= l==l_;
                l = l_;
                l_ = r, r_ = N;
                while (l_ < r_) {
                    ll m = (l_+r_+1)/2;
                    if (bit.sum(m)-bit.sum(r) <= x) {
                        l_ = m;
                    } else {
                        r_ = m-1;
                    }
                }
                x += bit.sum(l_)-bit.sum(r);
                bad &= r==l_;
                r = l_;
                if (bad) break;
            }
            if (good || (l == 1 && r == N)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}