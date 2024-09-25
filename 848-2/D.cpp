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

int T, N;
ll dp[1000003];
ll in[1000003];

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpow(a, b / 2);
    if (b % 2) return mul(mul(res, res), a);
    else return mul(res, res);
}

ll inv(ll a) {
    return binpow(a, MOD - 2);
}

ll frac(ll a, ll b) {
    return mul(a, in[b]);
}

int main () {
    // auto start = chrono::high_resolution_clock::now();
    cin.tie(0);
    ios::sync_with_stdio(false);
    for (ll i = 1; i <= 1000000; i++) {
        in[i] = inv(i);
    }
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    // cout << duration.count() << endl;
    cin >> T;
    while (T--) {
        cin >> N;
        string s1, s2;
        cin >> s1 >> s2;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        dp[0] = 0;
        dp[N] = 1;
        for (ll i = N-1; i >= 1; i--) {
            dp[i] = add(mul(dp[i+1], frac(N-i, i+1)),1);
        }
        for (ll i = 1; i <= cnt; i++) {
            dp[i] = add(dp[i-1], mul(frac(N, i), dp[i]));
        }
        cout << dp[cnt] << endl;
    }
    // auto stop2 = chrono::high_resolution_clock::now();
    // auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2-stop);
    // cout << duration2.count() << endl;
}