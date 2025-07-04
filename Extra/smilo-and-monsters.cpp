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

int T, N;
ll a[200005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            a[i] = x;
        }
        sort(a, a+N);
        ll ans = 0;
        int l = 0;
        int r = N-1;
        while (l <= r) {
            ll x = a[r];
            if (x == 1) {
                ans++;
                r--;
                continue;
            }
            ll cnt = x;
            while (cnt > 0 && l < r) {
                ll y = min(cnt, a[l]);
                cnt -= y;
                a[l] -= y;
                if (a[l] == 0) {
                    l++;
                }
            }
            r--;
            if (cnt == 0) {
                ans += x+1;
            } else {
                ans += (2*x-cnt+1)/2+1;
            }
        }
        cout << ans << endl;
    }
}