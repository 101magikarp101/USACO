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

int T, N;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        ll sum = 0;
        int cnt = 0;
        ll mi = 1e9;
        for (int i = 0; i < N; i++) {
            ll x; cin >> x;
            sum += abs(x);
            if (x < 0) {
                cnt++;
            }
            mi = min(mi, abs(x));
        }
        if (cnt%2) {
            sum -= 2*mi;
        }
        cout << sum << "\n";
    }
}