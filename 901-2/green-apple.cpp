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

ll T, N, M;

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        ll m = M;
        ll n = N-M*(N/M);
        ll g = gcd(N, M);
        N /= g;
        M /= g;
        N -= M*(N/M);
        while (M % 2 == 0) {
            M /= 2;
        }
        if (M == 1) {
            ll ans = __builtin_popcount(N);
            ans *= m;
            if (ans > 0) {
                ans -= n;
            }
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}