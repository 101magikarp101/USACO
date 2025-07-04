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
ll a[100002];

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int o = 0, e = 0;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            sum += a[i];
            if (a[i] % 2 == 0) {
                e++;
            } else {
                o++;
            }
            ll res = sum-o/3;
            if (o % 3 == 1 && (o > 1 || e > 0)) {
                res--;
            }
            cout << res << " ";
        }
        cout << endl;
    }
}