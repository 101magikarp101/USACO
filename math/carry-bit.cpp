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
#include <unordered_set>
 
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K;
ll p2[1000001];
ll p3[1000001];
ll fac[1000001];

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll res = binpow(a, b/2);
    res = mul(res, res);
    if (b%2) res = mul(res, a);
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

ll nck(ll n, ll k) {
    if (k > n) return 0;
    if (k < 0 || n < 0) return 0;
    return di(fac[n], mul(fac[k], fac[n-k]));
}

int main () {
    cin >> N >> K;
    p2[0] = 1;
    for (ll i = 1; i <= N; i++) {
        p2[i] = mul(p2[i-1], 2);
    }
    p3[0] = 1;
    for (ll i = 1; i <= N; i++) {
        p3[i] = mul(p3[i-1], 3);
    }
    fac[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    ll ans = 0;
    for (ll i = 0; i <= K; i++) {
        ll res1 = nck(K-1, i);
        res1 = mul(res1, p2[i]);
        ll res2 = nck(N-2*K+i, K-i-1);
        ll res3 = p3[N-2*K+i];
        ll res = mul(res1, mul(res2, res3));
        cout << "i: " << i << " res1: " << res1 << " res2: " << res2 << " res3: " << res3 << " res: " << res << endl;
        ans = add(ans, res);
    }
    cout << ans << endl;
}