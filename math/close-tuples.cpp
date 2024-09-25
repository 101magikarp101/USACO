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

int T, N, M, K;
ll a[200005];
ll fac[200005];
map<ll, ll> cnt;

ll mult(ll a, ll b) {
    return (a*b)%MOD2;
}

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll res = binpow(a, b/2);
    res = mult(res, res);
    if (b%2) res = mult(res, a);
    return res;
}

ll di(ll a, ll b) {
    return mult(a, binpow(b, MOD2-2));
}

ll nck(ll n, ll k) {
    if (k > n) return 0;
    if (k < 0) return 0;
    return di(fac[n], mult(fac[k], fac[n-k]));
}

int main () {
    cin >> T;
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = mult(fac[i-1], i);
    }
    while (T--) {
        cnt.clear();
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        vt<pll> v;
        for (auto i : cnt) {
            v.push_back({i.first, i.second});
        }
        vt<ll> pre(v.size());
        pre[0] = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            pre[i] = pre[i-1]+v[i].second;
        }
        ll ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ll cur = v[i].second;
            int idx = lower_bound(v.begin(), v.end(), pll(v[i].first+K+1, 0))-v.begin();
            idx--;
            ll val = pre[idx] - (i ? pre[i-1] : 0);
            if (val < M) continue;
            ll res = 0;
            for (int j = 1; j <= cur; j++) {
                res = add(res, mult(nck(cur, j), nck(val-cur, M-j)));
            }
            // cout << "i: " << i << " idx: " << idx << " val: " << val << " res: " << res << endl;
            ans = add(ans, res);
        }
        cout << ans << endl;
    }
}