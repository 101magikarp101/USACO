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
multiset<pii> s;
map<int, vt<int>> m;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        m.clear();
        s.clear();
        a[0] = -1;
        int z = 0;
        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            a[i] = x;
            m[x].push_back(i);
            if (x == 0) {
                z++;
            }
        }
        if (z != 1) {
            cout << "NO" << endl;
            continue;
        }
        bool ans = true;
        for (auto i : m) {
            if (i.first == 0) {
                for (int j = 0; j < i.second.size(); j++) {
                    s.insert({i.second[j], i.first});
                }
            } else {
                int pre = i.first - 1;
                bool good = true;
                for (int j = 0; j < i.second.size(); j++) {
                    auto it = s.lower_bound({i.second[j], pre});
                    bool res1 = false, res2 = false;
                    if (it != s.end()) {
                        res1 = (it->second == pre);
                    }
                    if (it != s.begin()) {
                        it--;
                        res2 = (it->second == pre);
                    }
                    // cout << "i: " << i.first << " j: " << j << " pre: " << pre << endl;
                    // cout << "res1: " << res1 << " res2: " << res2 << endl;
                    good = res1 || res2;
                    if (!good) {
                        break;
                    }
                }
                if (!good) {
                    ans = false;
                    break;
                }
                for (int j = 0; j < i.second.size(); j++) {
                    s.insert({i.second[j], i.first});
                }
            }
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}