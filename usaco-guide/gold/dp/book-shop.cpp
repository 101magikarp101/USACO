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

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

struct item {
    int w, v;
};

int N, X;
item a[1002];
int dp[100005];

int main() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> a[i].w;
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i].v;
    }
    for (int i = 1; i <= X; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = X; j >= 0; j--) {
            if (j - a[i].w >= 0 && dp[j-a[i].w] != INT_MIN) {
                dp[j] = max(dp[j], dp[j-a[i].w] + a[i].v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= X; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}