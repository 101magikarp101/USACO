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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N;
int tar[751][751];
int fli[751][751];
int dp[751][751];

int main() {
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        string s; cin >> s;
        for (int j = 1; j <= N-i; j++) {
            tar[i][i+j] = s[j-1] - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= N-1; i++) {
        fli[i][i+1] = tar[i][i+1];
        dp[i][i+1] = tar[i][i+1];
        ans += tar[i][i+1];
    }
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j+i <= N-1; j++) {
            for (int k = j+1; k <= j+i; k++) {
                dp[j][j+i+1] += fli[j][k]*tar[k][j+i+1];
            }
            dp[j][j+i+1] %= 2;
            if (dp[j][j+i+1] != tar[j][j+i+1]) {
                fli[j][j+i+1] = 1;
                ans++;
                dp[j][j+i+1] = !dp[j][j+i+1];
            } else {
                fli[j][j+i+1] = 0;
            }
        }
    }
    cout << ans << endl;
}