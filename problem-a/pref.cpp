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
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll add(ll a, ll b) {
    return (a + b) % MOD2;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2 - 2);
}

ll nck(ll n, ll k) {
    ll res = 1;
    for (ll i = k + 1; i <= n; i++) {
        res = mul(res, i);
    }
    for (ll i = 1; i <= n - k; i++) {
        res = mul(res, inv(i));
    }
    return res;
}

ll N;
ll K;
vt<ll> a;

int main () {
    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll hm = 1;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans = add(ans, mul(hm, a[N-i-1]));
        hm = mul(hm, mul(K+i+1, inv(i+1)));
    }
    cout << ans << endl;
}