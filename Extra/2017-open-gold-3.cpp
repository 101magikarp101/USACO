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

struct seg {
    int l, r;
};

int N;
int a[100005];
seg s[100005];

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        s[i].l = INT_MAX;
        s[i].r = INT_MIN;
    }
    for (int i = 1; i <= N; i++) {
        if (a[i] != 0) {
            s[a[i]].l = min(s[a[i]].l, i);
            s[a[i]].r = max(s[a[i]].r, i);
        }
    }
    sort(s+1, s+N+1, [](seg a, seg b) {
        return a.l < b.l;
    });
    // cout << "s: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << s[i].l << " " << s[i].r << endl;
    // }
    deque<seg> q;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (s[i].l == INT_MAX) break;
        // cout << "i: " << i << endl;
        while (q.size() && s[i].l > q.back().r) {
            q.pop_back();
        }
        if (!q.empty() && s[i].l <= q.back().r && s[i].r > q.back().r) {
            ans = -1;
            break;
        }
        q.push_back(s[i]);
        ans = max(ans, (int)q.size());
    }
    cout << ans << endl;
    return 0;
}