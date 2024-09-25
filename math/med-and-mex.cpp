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

int T, N;
ll f[200005];

ll fac(ll a) {
    if (a < 0) return 0;
    return f[a];
}

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll res = binpow(a, b/2);
    res = mult(res, res);
    if (b%2) res = mult(res, a);
    return res;
}

ll di(ll a, ll b) {
    return mult(a, binpow(b, MOD-2));
}

ll nck(ll n, ll k) {
    if (k > n) return 0;
    if (k < 0) return 0;
    return di(fac(n), mult(fac(k), fac(n-k)));
}

int main () {
    cin >> T;
    f[0] = 1;
    for (ll i = 1; i <= 200002; i++) {
        f[i] = mult(f[i-1], i);
    }
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            ll res = nck(N-(i+1), i-2);
            // cout << "i: " << i << " res: " << res << endl;
            res = mult(res, fac(2*i-2));
            // cout << "i: " << i << " res: " << res << endl;
            res = mult(res, fac(N-2*i+3));
            // cout << "i: " << i << " res: " << res << endl;
            cout << res << " ";
        }
        cout << endl;
    }
}