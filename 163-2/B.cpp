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
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;
int a[200005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int prev = 0;
        bool ans = true;
        for (int i = 0; i < N; i++) {
            if (a[i]>10) {
                if (a[i]/10>=prev && a[i]%10 >=a[i]/10) {
                    prev = a[i]%10;
                } else if (a[i]>=prev) {
                    prev = a[i];
                } else {
                    ans = false;
                    break;
                }
            } else {
                if (a[i]>=prev) {
                    prev = a[i];
                } else {
                    ans = false;
                    break;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}