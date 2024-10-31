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

struct rect {
    int w, h;
};

int W, H;
int N;
rect a[203];
int dp[603][603];

int main () {
    cin >> W >> H;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;
        a[i] = {w, h};
    }
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= H; j++) {
            dp[i][j] = i*j;
        }
    }
    for (int i = 0; i < N; i++) {
        dp[a[i].w][a[i].h] = 0;
    }
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= H; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout << dp[W][H] << endl;
}