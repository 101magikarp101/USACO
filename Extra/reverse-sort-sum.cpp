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
int ans[200005];

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            ans[i] = -1;
        }
        for (int i = 0; i < a[0]; i++) {
            ans[i] = 1;
        }
        ans[a[0]] = 0;
        int r = a[0]+1;
        for (int i = 1; i < N; i++) {
            if (a[i] == 0) {
                ans[i] = 0;
                r++;
            }
            else {
                if (ans[i] == -1) ans[i] = 1;
                int res = a[i]-i*ans[i];
                for (;r < i+res && r < N; r++) {
                    ans[r] = 1;
                }
                if (r < N) {
                    ans[r] = 0;
                    r++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}