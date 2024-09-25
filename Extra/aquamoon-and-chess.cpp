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

int T, N;
ll fac[100005];
ll in[100005];
bool vis[100005];

ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpow(a, b/2);
    res = mul(res, res);
    if (b%2) res = mul(res, a);
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD-2);
}

ll nck(ll n, ll k) {
    if (k > n) return 0;
    if (n < 0 || k < 0) return 0;
    return mul(fac[n], mul(in[k], in[n-k]));
}

int main () {
    cin >> T;
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    for (int i = 0; i <= 100000; i++) {
        in[i] = inv(fac[i]);
    }
    while (T--) {
        cin >> N;
        string s;
        cin >> s;
        int grp = 0;
        int z = (s[0] == '0' ? 1 : 0);
        for (int i = 1; i < N; i++) {
            vis[i] = false;
            if (s[i] == '1' && s[i-1] == '1' && !vis[i-1]) {
                grp++;
                vis[i] = true;
                vis[i-1] = true;
            }
            if (s[i] == '0') z++;
        }
        // cout << "grp: " << grp << endl;
        ll ans = nck(z+grp, grp);
        cout << ans << endl;
    }
}