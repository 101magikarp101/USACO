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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

ll N, Q;
ll pre[200005];
ll suf[200005];
ll arr[200005];

ll get(ll x, ll a, ll b) {
    if (x <= 0 || x >= N+1) {
        return LLONG_MAX;
    }
    ll res = a*(x*arr[x] - pre[x]) - b*((N-x+1)*arr[x] - suf[x]);
    return res;
}

int main() {
    cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    for (ll i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + arr[i];
    }
    for (ll i = N; i >= 1; i--) {
        suf[i] = suf[i+1] + arr[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll a, b; cin >> a >> b;
        double x = (double)(b*N)/(double)(a+b);
        ll i1 = (ll)ceil(x);
        ll i2 = (ll)floor(x);
        ll ans = min(get(i1, a, b), get(i2, a, b));
        cout << ans << endl;
    }
}