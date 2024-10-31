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

ll N;
ll dp[1 << 21];
bool arr[21][21];

ll add(ll a, ll b) {
    return (a + b) % MOD2;
}

int main () {
    // auto start = chrono::high_resolution_clock::now();
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    dp[0] = 1;
    for (int i = 0; i < (1 << N); i++) {
        int cnt = __builtin_popcount(i);
        for (int j = 0; j < N; j++) {
            if (arr[cnt][j] && !(i & (1 << j))) {
                dp[i | (1 << j)] = add(dp[i | (1 << j)], dp[i]);
            }
        }
    }
    cout << dp[(1 << N) - 1] << endl;
    // auto end = chrono::high_resolution_clock::now();
    // ll time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count();
    // cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
}