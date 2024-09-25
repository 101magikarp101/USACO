#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        int ans = 0;
        int ma = 0;
        for (int i = 1; i <= N; i++) {
            ma = max(ma, a[i]);
            if (ma == i) ans++;
        }
        vt<int> v;
        ma = 0;
        for (int i = 1; i <= N-1; i++) {
            int m1 = max(ma, a[i]);
            int m2 = max(ma, a[i+1]);
            int cur = 0;
            if (m1 == i) cur--;
            if (m2 == i) cur++;
            v.push_back(cur);
            ma = max(ma, a[i]);
        }
        // cout << "v: ";
        // for (int i : v) cout << i << " ";
        // cout << "\n";
        int best = 0;
        int mi = 0;
        int sum = 0;
        for (int i = 0; i < v.size(); i+=2) {
            sum += v[i];
            best = max(best, sum-mi);
            mi = min(mi, sum);
        }
        sum = 0;
        mi = 0;
        for (int i = 1; i < v.size(); i+=2) {
            sum += v[i];
            best = max(best, sum-mi);
            mi = min(mi, sum);
        }
        ans += best;
        cout << ans << "\n";
    }
    return 0;
}