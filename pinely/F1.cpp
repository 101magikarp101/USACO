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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N;
ll a[200002];

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        a[0] = 0;
        if (a[1] > 1) {
            cout << 0 << endl;
            continue;
        }
        if (a[N] != N) {
            cout << 0 << endl;
            continue;
        }
        ll cur = 0;
        ll ans = 1;
        for (int i = 1; i <= N; i++) {
            ll x = a[i] - a[i - 1];
            if (x == 1) {
                ans = mult(ans, (2*cur+1));
            } else if (x == 2) {
                ans = mult(ans, mult(cur, cur));
                cur--;
            } else if (x == 0) {
                cur++;
            } else {
                ans = 0;
                break;
            }
        }
        cout << ans << endl;
    }
}