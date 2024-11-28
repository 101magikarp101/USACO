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

ll mult(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll res = binpow(a, b/2);
    res = mult(res, res);
    if (b%2 == 1) {
        res = mult(res, a);
    }
    return res;
}

ll di(ll a, ll b) {
    return mult(a, binpow(b, MOD2-2));
}

ll nck(ll n, ll k) {
    ll res = 1;
    for (ll i = n-k+1; i <= n; i++) {
        res = mult(res, i);
    }
    for (ll i = 1; i <= k; i++) {
        res = di(res, i);
    }
    return res;
}

ll n, m;

int main () {
    cin >> n >> m;
    cout << nck(n+m-1, m) << endl;
}