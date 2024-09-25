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
struct pll {ll x, y;};

ll N, K, T;
ll a[300005];
int ne[300005];

int main() {
    cin >> N >> K >> T;
    set<ll> s;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() <= T) {
        cout << 1 << endl;
        return 0;
    }
    map<ll, int> m;
    int r = 0;
    for (int i = 0; i < N; i++) {
        while (m.size() <= T) {
            m[a[r%N]]++;
            r++;
        }
        ne[i] = (r-1)%N;
        m[a[i]]--;
        if (m[a[i]] == 0) {
            m.erase(a[i]);
        }
    }
    cout << "ne: " << endl;
    for (int i = 0; i < N; i++) {
        cout << ne[i]%N << " ";
    }
    cout << endl;
    map<int, pll> m2;
    ll ans = 0;
    int i = 0;
    int cnt = 0;
    while (true) {
        if (ne[i] < i) {
            ans++;
        }
        m2[i] = {ans, cnt};
        i = ne[i];
        if (m2.find(i) != m2.end()) {
            cout << ans+m2[i]
        }
        cnt++;
    }
    cout << ans << endl;
    return 0;
}