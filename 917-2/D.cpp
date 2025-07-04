#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

ll T, N, K;
ll p[200005];
ll q[200005];

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

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (ll i = 1; i <= N; i++) {
            cin >> p[i];
        }
        for (ll i = 1; i <= K; i++) {
            cin >> q[i];
        }
        BIT<ll> bit(K + 1);
        ll ans = 0;
        ll sum = 0;
        for (ll i = K; i >= 1; i--) {
            ll tmp = q[i] + 1;
            sum += bit.sum(tmp);
            bit.set(tmp, 1);
        }
        sum = mult(sum, N);
        ans = sum;
        BIT<ll> bit2(2 * N);
        ll lim = floor(log2(2 * N))+1;
        for (ll i = N; i >= 1; i--) {
            for (ll j = lim; j >= -lim; j--) {
                ll l, r;
                if (j >= K) continue;
                if (j >= 0) {
                    r = p[i] * (1 << (j + 1)) - 1;
                    l = p[i] * (1 << j);
                } else {
                    r = ceil((double)p[i] / (double)(1 << (-j - 1))) - 1;
                    l = ceil((double)p[i] / (double)(1 << (-j)));
                }
                ll res;
                if (l <= r) {
                    res = bit2.sum(r) - bit2.sum(l - 1);
                    res %= MOD;
                } else {
                    continue;
                }
                ll cnt = (K * (K + 1) / 2) - ((j+1) * K) + (j * (j + 1) / 2)*(j >= 0 ? 1 : -1);
                if (j <= -K) cnt = K*K;
                cnt %= MOD;
                ans = add(ans, mult(res, cnt));
            }
            bit2.set(p[i], 1);
        }
        cout << ans << endl;
    }
}