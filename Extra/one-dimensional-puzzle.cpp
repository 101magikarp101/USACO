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

int T;
ll a, b, c, d;

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
    while (b>0) {
        if (b&1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD-2);
}

ll nck(ll n, ll k) {
    if (k<0) return 1;
    ll res = 1;
    for (ll i = n; i>n-k; i--) {
        res = mul(res, i);
    }
    for (ll i = 1; i<=k; i++) {
        res = mul(res, inv(i));
    }
    return res;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        if (a==0&&b==0) {
            if (c==0||d==0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (a==b) {
            ll ans = nck(c+a-1,a-1);
            ans = mul(ans, nck(d+b,b));
            ll res = nck(d+b-1,a-1);
            res = mul(res, nck(c+a,a));
            ans = add(ans, res);
            cout << ans << endl;
        } else if (a==b+1) {
            ll ans = nck(c+a-1,a-1);
            ans = mul(ans, nck(d+b,b));
            cout << ans << endl;
        } else if (a+1==b) {
            ll ans = nck(d+b-1,b-1);
            ans = mul(ans, nck(c+a,a));
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}