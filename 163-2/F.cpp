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
struct pii {int x, y;};
struct pll {int x, y;};

int N, Q;
ll a[300005], b[300005];
ll pa[300005], pb[300005];
ll fac[1000005];
ll inv[1000005];
ll prefac[1000005];

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll nck(ll n, ll k) {
    return mul(fac[n], mul(inv[k], inv[n-k]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    inv[1000000] = binpow(fac[1000000], MOD-2);
    for (int i = 999999; i >= 0; i--) {
        inv[i] = mul(inv[i+1], i+1);
    }
    cin >> N >> Q;
    ll suma = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        suma+=a[i];
    }
    ll sumb = 0;
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
        sumb+=b[i];
    }
    for (int i = 1; i <= N; i++) {
        pa[i]=pa[i-1]+a[i];
    }
    for (int i = 1; i <= N; i++) {
        pb[i]=pb[i-1]+b[i];
    }
    prefac[0] = nck(sumb, 0);
    for (int i = 1; i <= sumb; i++) {
        prefac[i] = add(prefac[i-1], nck(sumb, i));
    }
    ll two = binpow(2, sumb*(MOD-2));
    while (Q--) {
        int l, r;
        cin >> l >> r;
        ll k = pa[r]-pa[l-1];
        k-=suma-k;
        k*=-1;
        ll n = pb[r]-pb[l-1];
        ll hm = n-k-1;
        // cout << "n: " << n << " k: " << k << " hm: " << hm << endl;
        if (hm<0) {
            cout << 0 << endl;
        } else if (hm>=sumb)  {
            cout << 1 << endl;
        } else {
            ll ans = prefac[hm];
            ans = mul(ans, two);
            cout << ans << endl;
        }
    }
    return 0;
}