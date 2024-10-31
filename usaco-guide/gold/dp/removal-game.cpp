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

int N;
ll a[5005][5005];
ll pre[5005];

int main() {
    cin >> N;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= N; i++) {
        cin >> a[i][i];
    }
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + a[i][i];
    }
    for (int j = 1; j <= N; j++) {
        for (int i = j-1; i >= 1; i--) {
            a[i][j] = max(a[i][i] + pre[j] - pre[i] - a[i+1][j], a[j][j] + pre[j-1] - pre[i-1] - a[i][j-1]);
        }
    }
    cout << a[1][N] << endl;
}