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

struct node {
    int col;
    int p;
    vt<int> c;
};

int T, X;
int N;
node a[40005];

int solve(int n, int c) {
    int ans = 0;
    if (c == 0) {
        if (a[n].c.size()+a[n].p <= 2) {
            ans++;
            for (int i : a[n].c) {
                ans += solve(i, 1);
            }
            // cout << "n: " << n << " c: " << c << " ans: " << ans << endl;
            return ans;
        }
    }
    for (int i : a[n].c) {
        ans += solve(i, 0);
    }
    // cout << "n: " << n << " c: " << c << " ans: " << ans << endl;
    return ans;
}

int main () {
    cin >> T >> X;
    while (T--) {
        cin >> N;
        a[1] = {-1, 0, {}};
        for (int i = 2; i <= N+1; i++) {
            int p; cin >> p;
            a[i] = {-1, 1, {}};
            a[p].c.push_back(i);
        }
        int ans = solve(1, 0);
        cout << ans << endl;
    }
}