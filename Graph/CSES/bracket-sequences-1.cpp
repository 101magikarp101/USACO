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

int T, N;
int a[200005];

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
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll di(ll a, ll b) {
    return mul(a, binpow(b, MOD2-2));
}

ll nck(ll n, ll k) {
    ll res = 1;
    for (ll i = n; i > n-k; i--) {
        res = mul(res, i);
    }
    for (ll i = 1; i <= k; i++) {
        res = di(res, i);
    }
    return res;
}

int main() {
    cin >> N;
    if (N%2==1) {
        cout << 0 << endl;
        return 0;
    } else {
        N /= 2;
    }
    ll ans = di(nck(2*N, N), N+1);
    cout << ans << endl;
    return 0;
}