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

ll N;

int main () {
    cin >> N;
    ll ans = 0;
    for (ll i = 2; i*i <= N; i++) {
        if (N%i == 0) {
            ll cnt = 0;
            while (N%i == 0) {
                N /= i;
                cnt++;
            }
            for (int j = 1; cnt - j >= 0; j++) {
                cnt -= j;
                ans++;
            }
        }
    }
    if (N > 1) {
        ans++;
    }
    cout << ans << endl;
}