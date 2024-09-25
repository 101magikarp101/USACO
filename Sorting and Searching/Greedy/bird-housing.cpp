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

#define ll long long

using namespace std;

int N;
int arr[1000001];
int dp[1000001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if (N == 1) {
        cout << arr[0] << endl;
        return 0;
    } else if (N == 2) {
        cout << max(arr[0], arr[1]) << endl;
        return 0;
    }
    dp[0] = arr[0];
    dp[1] = arr[1];
    for (int i = 2; i < N; i++) {
        dp[i] += max(dp[i-2], dp[i-3]) + arr[i];
    }
    cout << max(dp[N-1], dp[N-2]) << endl;
}