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
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

int T, N;
ll a[200005];
ll diff[200005];

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        ll ma = -1e10;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        if (N==1) {
            cout << 1 << endl;
            continue;
        }
        // cout << "ma: " << ma << endl;
        for (int i = 0; i < N-1; i++) {
            diff[i] = abs(a[i]-a[i+1]);
        }
        ll g = diff[0];
        for (int i = 0; i < N-1; i++) {
            g = gcd(g, diff[i]);
        }
        // cout << "g: " << g << endl;
        sort(a, a+N, greater<ll>());
        ll first = -1;
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans += (ma-a[i])/g;
            if ((ma-a[i])/g != i && first == -1) {
                first = i;
            }
        }
        if (first == -1) {
            first = N;
        }
        ans += first;
        cout << ans << endl;
    }
}