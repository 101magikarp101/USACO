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
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

ll T, N;
ll binpow[100002];

ll sub(ll a, ll b) {
    return ((a-b)%MOD+MOD)%MOD;
}

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

int main() {
    binpow[0] = 1;
    for (int i = 1; i <= 100001; i++) {
        binpow[i] = (binpow[i-1]*2)%MOD;
    }
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = 0;
        N--;
        for (ll i = 0; i < N; i++) {
            ll res = mult(binpow[N-i]-1, sub(binpow[N+1], binpow[N-i]));
            res = mult(res, binpow[i+1]);
            ans = add(ans, res);
        }
        ans = mult(ans, 2);
        cout << ans << endl;
    }
}