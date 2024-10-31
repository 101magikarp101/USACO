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

int N, M, K;
ll dp[1000005];
ll pre[1000005];

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow (ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll res = binpow(a, b/2);
    if (b%2) {
        return mult(mult(res, res), a);
    } else {
        return mult(res, res);
    }
}

int main () {
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    cin >> N >> M >> K;
    for (int i = 1; i < K; i++) {
        dp[i] = binpow(M, i);
        pre[i] = add(pre[i-1], dp[i]);
    }
    for (int i = K; i <= N; i++) {
        dp[i] = sub(pre[i-1], pre[i-K]);
        dp[i] = mult(dp[i], M-1);
        pre[i] = add(pre[i-1], dp[i]);
    }
    cout << sub(binpow(M, N), dp[N]) << endl;
}