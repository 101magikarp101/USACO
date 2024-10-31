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

ll der[] = {1, 0, 1, 2, 9};

ll nck(ll n, ll k) {
    ll res = 1;
    for (ll i = n-k+1; i <= n; i++) {
        res *= i;
    }
    for (ll i = 1; i <= k; i++) {
        res /= i;
    }
    return res;
}

ll N, K;

int main () {
    cin >> N >> K;
    ll ans = 0;
    for (ll i = 0; i <= K; i++) {
        ans += nck(N, i)*der[i];
    }
    cout << ans << endl;
}