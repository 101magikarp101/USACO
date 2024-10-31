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

int N;
ll cnt[1000003];
ll res[1000003];
ll in[1000003];

ll mult(ll a, ll b) {
    return (a*b)%MOD;
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

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll inv(ll a) {
    return binpow(a, MOD-2);
}

int main () {
    for (int i = 1; i <= 1000000; i++) {
        in[i] = inv(i);
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            ll y;
            cin >> y;
            res[y] += in[x];
            res[y] %= MOD;
            cnt[y]++;
        }
    }
    ll sq = inv(mult(N, N));
    ll ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        ans = add(ans, mult(mult(res[i], sq), cnt[i]));
    }
    cout << ans << endl;
}