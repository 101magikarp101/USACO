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
        bool ans = true;
        for (int i = 1; i < N-1; i++) {
            int res = a[i-1];
            a[i-1]-=res;
            a[i]-=res*2;
            a[i+1]-=res;
            if (a[i-1]<0 || a[i]<0 || a[i+1]<0) {
                ans = false;
                break;
            }
        }
        cout << (ans && a[N-1]==0 && a[N-2]==0 ? "YES" : "NO") << endl;
    }
    return 0;
}