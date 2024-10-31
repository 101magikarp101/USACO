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

int N, K;
vt<vt<vt<int>>> dp;
int arr[505];

int main () {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr, arr+N);
    dp = vt<vt<vt<int>>>(N+1, vt<vt<int>>(K+1, vt<int>()));
    dp[0][0] = {0};
    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 1; j--) {
            if (j-arr[i] >= 0) {
                vt
            }
        }
    }
}