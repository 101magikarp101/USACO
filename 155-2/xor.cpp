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
#include <chrono>

#define ll long long

using namespace std;

int N;
int a[300005];
ll MOD = 998244353;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll s[2];
    ll num[2];
    int sum;
    for (int i = 0; i <= 31; i++) {
        memset(num, 0, sizeof(num));
        memset(s, 0, sizeof(s));
        num[0] = 1;
        sum = 0;
        for (int j = 0; j < N; j++) {
            s[0] += num[0];
            s[0] %= MOD;
            s[1] += num[1];
            s[1] %= MOD;
            sum += (a[j]>>i)&1;
            sum %= 2;
            if (sum == 0) {
                ans += (s[1]<<i) % MOD;
                ans %= MOD;
            } else {
                ans += (s[0]<<i) % MOD;
                ans %= MOD;
            }
            num[sum]++;
            // cout << "i: " << i << endl;
            // cout << "num: " << num[0] << " " << num[1] << endl;
            // cout << "s: " << s[0] << " " << s[1] << endl;
            // cout << "sum: " << sum << endl;
            // cout << "ans: " << ans << endl;
            // cout << endl;
        }
    }
    cout << ans << endl;
}