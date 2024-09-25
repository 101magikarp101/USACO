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

int Q, K;
ll dp[5005];

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

int main () {
    cin >> Q >> K;
    dp[0] = 1;
    for (int q = 0; q < Q; q++) {
        char c;
        ll x;
        cin >> c >> x;
        if (c == '+') {
            for (int i = K; i >= 1; i--) {
                if (i-x>=0) {
                    dp[i] = add(dp[i], dp[i-x]);
                }
            }
            cout << dp[K] << endl;
        } else if (c == '-') {
            for (int i = 1; i <= K; i++) {
                if (i-x>=0) {
                    dp[i] = sub(dp[i], dp[i-x]);
                }
            }
            cout << dp[K] << endl;
        }
    }
}