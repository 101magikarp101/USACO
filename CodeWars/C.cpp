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

ll T, N;
ll a[500005];
ll b[500005];

ll highest(ll x) {
    //find highest bit
    ll ans = -1;
    while (x) {
        x >>= 1;
        ans++;
    }
    return ans;
}

int main () {
    // cout << bitset<64>(2305843009213693949) << endl;
    cin >> T;
    memset(b, 0, sizeof(b));
    while (T--) {
        cin >> N;
        if (N==1) {
            ll x; cin >> x;
            cout << (1LL<<x)-1 << endl;
            continue;
        }
        for (ll i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (ll i = 1; i < N; i++) {
            ll x = a[i-1]-a[i];
            if (x>=0) {
                b[i] = 1LL<<(x+1);
            } else {
                b[i] = b[i-1]+1;
            }
        }
        //count number of 1s
        ll y = a[N-1]-__builtin_popcountll(b[N-1]);
        ll x = highest(b[N-1]);
        // cout << "x: " << x << " y: " << y << endl;
        if (y < 0) {
            cout << -1 << endl;
            continue;
        }
        // cout << bitset<64>(b[N-1]) << endl;
        for (ll i = x+1; i <= x+y; i++) {
            b[N-1] |= (1LL<<i);
        }
        //print binary
        // cout << bitset<64>(b[N-1]) << endl;
        bool good = true;
        for (ll i = N-2; i >= 0; i--) {
            b[i] = b[i+1]-1;
            if (b[i] < 0) {
                good = false;
                break;
            }
            ll x = __builtin_popcountll(b[i]);
            // cout << "i: " << i << " x: " << x << " a[i]: " << a[i] << " b[i]: " << b[i] << endl;
            if (x!=a[i]) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << b[0] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}