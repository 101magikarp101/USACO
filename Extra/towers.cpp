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

ll N, D;
vector<ll> a;
ll MOD = 1e9+9;

int main() {
    cin >> N >> D;
    a.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 1;
    for (ll i = 1; i < N; i++) {
        ll idx = lower_bound(a.begin(), a.end(), a[i]-D) - a.begin();
        ans *= (i-idx+1);
        ans %= MOD;
    }
    cout << ans << endl;
}