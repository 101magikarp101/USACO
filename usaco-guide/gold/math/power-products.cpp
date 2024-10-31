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

struct prime {
    ll p, e;
};

ll N, K;
ll a[100005];
map<ll, ll> m[5];
ll mods[5] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};

ll mult(ll a, ll b, ll M) {
    return (a*b)%M;
}

ll add(ll a, ll b, ll M) {
    return (a+b)%M;
}

ll binpow(ll a, ll b, ll M) {
    if (b == 0) {
        return 1;
    }
    ll res = binpow(a, b/2, M);
    res = mult(res, res, M);
    if (b%2 == 1) {
        res = mult(res, a, M);
    }
    return res;
}

ll calc(vt<prime> v, ll M) {
    if (v.size() == 0) {
        return 0;
    }
    ll ans = 1;
    for (auto i : v) {
        ans = mult(ans, binpow(i.p, i.e, M), M);
    }
    return ans;
}

int main () {
    cin >> N >> K;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        vt<prime> v;
        for (int j = 2; j*j <= a[i]; j++) {
            if (a[i]%j == 0) {
                ll cnt = 0;
                while (a[i]%j == 0) {
                    a[i] /= j;
                    cnt++;
                }
                if (cnt%K != 0) {
                    v.push_back({j, cnt%K});
                }
            }
        }
        if (a[i] > 1) {
            v.push_back({a[i], 1});
        }
        ll res = 1e18;
        for (int j = 0; j < 5; j++) {
            ll val = calc(v, mods[j]);
            res = min(res, m[j][val]);
        }
        if (res != 1e18) {
            ans += res;
        }
        for (int j = 0; j < v.size(); j++) {
            v[j].e = K - v[j].e;
        }
        for (int j = 0; j < 5; j++) {
            ll val = calc(v, mods[j]);
            m[j][val]++;
        }
    }
    cout << ans << endl;
}