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
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N;
ll a[200004];

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        ll h = 0;
        int r = N;
        bool ans = true;
        for (int i = 1; i <= N; i++) {
            h++;
            while (r > 0 && h > a[r]) {
                r--;
            }
            if (r != a[i]) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}