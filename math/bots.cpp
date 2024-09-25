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

ll N;
ll fac[2000002];

ll mult(ll a, ll b) {
    return (a*b)%MOD2;
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
    return mult(a, binpow(b, MOD2-2));
}

int main () {
    cin >> N;
    N++;
    fac[0] = 1;
    for (ll i = 1; i <= 2*N; i++) {
        fac[i] = mult(fac[i-1], i);
    }
    ll ans = di(fac[2*N], mult(fac[N], fac[N]));
    ans--;
    cout << ans << endl;
}