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

int T;
string s;
ll MOD = 998244353;

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll factorial(ll n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = mult(ans, i);
    }
    return ans;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> s;
        int n = s.length();
        ll ans = 1;
        int cur = s[0];
        int cnt = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == cur) {
                cnt++;
            } else {
                cur = s[i];
                tot += cnt-1;
                ans = mult(ans, cnt);
                cnt = 1;
            }
        }
        ans = mult(ans, cnt);
        tot += cnt-1;
        ans = mult(ans, factorial(tot));
        cout << tot << " " << ans << endl;
    }
    return 0;
}