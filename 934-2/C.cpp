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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        map<int, int> m;
        for (int i=0; i<N; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        int ans = 0;
        bool hm = false;
        if (m.find(0) != m.end()) {
            ans++;
            if (m[0]==1) hm = true;
        } else {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= N; i++) {
            if (m.find(i) != m.end()) {
                if (m[i]>1) {
                    ans++;
                } else {
                    if (hm) {
                        break;
                    } else {
                        ans++;
                        hm = true;
                    }
                }
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}