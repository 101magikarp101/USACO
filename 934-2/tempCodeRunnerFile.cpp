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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        map<int, int> m;
        for (int i=0; i<N; i++) {
            int a;
            cin >> a;
            m[a]++;
        }
        int ans = 0;
        set<int> s;
        if (m.find(0) == m.end()) {
            cout << 0 << endl;
            continue;
        } else {
            ans++;
            s.insert(m[0]);
        }
        for (int i = 1; i < N; i++) {
            // cout << "i: " << i << " m[i]: " << m[i] << endl;
            if (m.find(i) != m.end()) {
                if (s.count(m[i]) == 0) {
                    ans++;
                    s.insert(m[i]);
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}