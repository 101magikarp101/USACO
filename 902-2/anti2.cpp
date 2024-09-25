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

using namespace std;

int N;
ll a[100002];
ll m[100002];
ll MOD = 998244353;
ll pow2[100002];

int main() {
    pow2[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        pow2[i] = (pow2[i-1]*2)%MOD;
    }
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j*j <= i; j++) {
            if (i % j == 0) {
                m[j] = max(m[j], a[i]);
                if (j*j != i) {
                    m[i/j] = max(m[i/j], a[i]);
                }
            }
        }
    }
    sort(m+1, m+N+1, greater<ll>());
    for (ll i = 1; i <= N; i++) {
        ll res = m[i]*pow2[N-i];
        res %= MOD;
        ans += res;
        ans %= MOD;
    }
    cout << ans << endl;
}