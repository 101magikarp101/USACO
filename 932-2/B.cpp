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
int a[100005];
multiset<int> s;

int main () {
    cin >> T;
    while (T--) {
        s.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int mex = 0;
        while (true) {
            if (s.find(mex) == s.end()) {
                break;
            }
            mex++;
        }
        set<int> s2;
        bool good = false;
        int ans = -1;
        for (int i = 0; i < N-1; i++) {
            if (a[i] < mex) {
                s2.insert(a[i]);
                s.erase(s.find(a[i]));
            }
            if (s2.size() == mex) {
                good = true;
                ans = i+1;
                break;
            }
        }
        int mex2 = 0;
        while (true) {
            if (s.find(mex2) == s.end()) {
                break;
            }
            mex2++;
        }
        if (good && mex2 == mex) {
            cout << 2 << endl;
            cout << 1 << " " << ans << endl;
            cout << ans+1 << " " << N << endl;
        } else {
            cout << -1 << endl;
        }
    }
}