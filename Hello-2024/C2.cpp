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
int a[200005];

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            a[i] = x;
        }
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        int x = a[1], y = 0;
        int res = 0;
        bool flag = false;
        for (int i = 2; i <= N; i++) {
            if (a[i] <= y) {
                y = a[i];
            } else if (a[i] <= x) {
                x = a[i];
            } else {
                flag = true;
                y = a[i];
                if (y > x) {
                    swap(x, y);
                }
                res++;
            }
        }
        cout << res-flag << endl;
    }
}