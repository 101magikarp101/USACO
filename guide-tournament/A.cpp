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

int N;
ll a[100005], b[100005];
ll dp[100005][2];

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        dp[i][0] = LLONG_MAX;
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        dp[i][1] = LLONG_MAX;
    }
    dp[N-1][0] = a[N-1];
    dp[N-1][1] = b[N-1];
    for (int i = N-2; i>=0; i--) {
        dp[i][0] = a[i]+2*min(dp[i+1][0], dp[i+1][1]);
        dp[i][1] = b[i]+min(dp[i+1][0], dp[i+1][1]);
    }
    cout << min(dp[0][0], dp[0][1]) << endl;
}