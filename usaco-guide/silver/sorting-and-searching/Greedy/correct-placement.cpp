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

struct person {
    ll x, y;
    int i;
};

int T, N;
person a[200005];
map<ll, vt<person>> m;
int ans[200005];

int main() {
    cin >> T;
    while (T--) {
        m.clear();
        cin >> N;
        for (int i= 0; i < N; i++) {
            ll x, y; cin >> x >> y;
            if (x < y) swap(x, y);
            a[i] = {x, y, i};
            m[x].push_back(a[i]);
        }
        for (auto &i : m) {
            sort(i.second.begin(), i.second.end(), [](person a, person b) {
                return a.y < b.y;
            });
        }
        int idx = -1;
        ll mi = LLONG_MAX;
        for (auto &i : m) {
            for (auto &j : i.second) {
                if (j.y > mi) {
                    ans[j.i] = idx+1;
                } else {
                    ans[j.i] = -1;
                }
            }
            if (i.second.front().y < mi) {
                mi = i.second.front().y;
                idx = i.second.front().i;
            }
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}