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
pll a[200005];

int main() {
    cin.tie();
    ios_base::sync_with_stdio();
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i].second;
        }
        sort(a, a + N, [](pll a, pll b) {
            return a.first + a.second > b.first + b.second;
        });
        ll al = 0, bo = 0;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                al += a[i].first-1;
            } else {
                bo += a[i].second-1;
            }
        }
        cout << al-bo << endl;
    }
}