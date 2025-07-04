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
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

ll N, X;
multiset<ll> ms;

int main() {
    cin >> X >> N;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        ms.insert(x);
    }
    ll ans = 0;
    while (ms.size() > 1) {
        ll a = *ms.begin();
        ms.erase(ms.begin());
        ll b = *ms.begin();
        ms.erase(ms.begin());
        ans += a + b;
        ms.insert(a + b);
    }
    cout << ans << endl;
}