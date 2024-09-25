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

int T;
ll X;

int main() {
    cin >> T;
    while (T--) {
        cin >> X;
        vt<ll> ans;
        ll cur = 0;
        for (int i = 0; i < 16; i++) {
            vt<ll> res;
            for (int j = 0; j < 4; j++) {
                if (X&(1LL<<(i*4+j))) {
                    cout << "i: " << i << " j: " << j << endl;
                    vt<ll> v;
                    for (int k = 0; k < j; k++) {
                        v.push_back(cur++);
                    }
                    reverse(v.begin(), v.end());
                    for (int k = 0; k < v.size(); k++) {
                        res.push_back(v[k]);
                    }
                }
            }
            reverse(res.begin(), res.end());
            for (int j = 0; j < res.size(); j++) {
                ans.push_back(res[j]);
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}