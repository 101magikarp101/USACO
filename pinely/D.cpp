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
ll K;
ll a[200005];

bool all_same() {
    for (int i = 1; i < N; i++) {
        if (a[i] != a[i-1]) {
            return false;
        }
    }
    return true;
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a + N);
        if (all_same()) {
            cout << 0 << endl;
            continue;
        }
        if (K < a[0]) {
            ll ans = 0;
            ll g = abs(a[0] - K);
            for (int i = 1; i < N; i++) {
                g = gcd(g, abs(a[i] - K));
            }
            for (int i = 0; i < N; i++) {
                ans += (a[i] - K)/g-1;
            }
            cout << ans << endl;
        } else if (K > a[N-1]) {
            ll ans = 0;
            ll g = abs(a[N-1] - K);
            for (int i = 0; i < N-1; i++) {
                g = gcd(g, abs(a[i] - K));
            }
            for (int i = 0; i < N; i++) {
                ans += (K - a[i])/g-1;
            }
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}