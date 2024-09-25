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

ll a, b, c, d;

ll solve(ll x) {
    if (x > c) return 0;
    if (x < b) {
        ll res = (c-b+1)*(b-x) + (c-b+1)*(c-b+2)/2;
        return res;
    } else {
        ll res = (c-x+1)*(c-x+2)/2;
        return res;
    }
}

int main () {
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (ll x = a; x <= b; x++) {
        ll l = c-x+1;
        ll r = d-x+1;
        ll res = solve(l) - solve(r+1);
        ans += res;
    }
    cout << ans << endl;
}