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

ll fun(ll n, ll k) {
    ll a = n - k + 1;
    if (a <= 0) {
        return 0;
    } else {
        return a*(a+1)/2;
    }
}

ll T;
ll N, K, Q;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K >> Q;
        int count = 0;
        ll ans = 0;
        for (int j = 0; j < N; j++) {
            ll temp;
            cin >> temp;
            if (temp <= Q) {
                count++;
            } else {
                ans += fun(count, K);
                count = 0;
            }
        }
        ans += fun(count, K);
        cout << ans << endl;
    }
}