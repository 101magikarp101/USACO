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

int N, M;
ll d[300005];
map<ll, int> m;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

ll di(ll a, ll b) {
    return mult(a, binpow(b, MOD - 2));
}

int main() {
    cin >> N >> M;
    ll cur = 0;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        d[i] = cur;
        cur += x;
        m[cur] = i;
    }
    if (cur % 2 == 1) {
        cout << binpow(M, N) << endl;
        return 0;
    }
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll x = d[i];
        if (x >= cur/2) {
            break;
        }
        if (m.find(x + cur / 2) != m.end()) {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << binpow(M, N) << endl;
        return 0;
    }
    ll ans = 0;
    ll bico = 1;
    ll rem = N - 2*cnt;
    ll hm = 1;
    for (int i = 0; i <= cnt; i++) {
        ll res = mult(bico, binpow(M - i, rem+cnt-i));
        res = mult(res, binpow(M-i-1, cnt-i));
        res = mult(res, hm);
        ans = add(ans, res);
        bico = di(mult(bico, cnt-i), i+1);
        hm = mult(hm, M-i);
    }
    cout << ans << endl;
}