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

ll T, N, M, K;
ll a[100005], d[200005], f[200005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < K; i++) {
            cin >> f[i];
        }
        sort(a, a+N);
        sort(d, d+M);
        sort(f, f+K);
        int idx = -1;
        ll res = -1;
        multiset<ll, greater<ll>> s;
        for (int i = 0; i < N-1; i++) {
            if (a[i+1]-a[i] > res) {
                res = a[i+1]-a[i];
                idx = i;
            }
            s.insert(a[i+1]-a[i]);
        }
        auto it = s.begin();
        if (N>2) {
            it++;
            if (*it==*s.begin()) {
                cout << *s.begin() << endl;
                continue;
            }
        }
        // cout << idx << " " << res << endl;
        ll tar1 = (a[idx+1]+a[idx])/2;
        ll tar2 = (a[idx+1]+a[idx]+1)/2;
        ll ans = res;
        for (int i = 0; i < M; i++) {
            ll t1 = tar1-d[i];
            ll t2 = tar2-d[i];
            // cout << "i: " << i << " t1: " << t1 << " t2: " << t2 << endl;
            auto it1 = lower_bound(f, f+K, t1);
            if (it1 != f+K) {
                ll hm1 = *it1+d[i]-a[idx];
                ans = min(ans, max(res-hm1, hm1));
                // cout << "hm1: " << hm1 << " ans: " << ans << endl;
            }
            if (it1 != f) {
                it1--;
                ll hm1 = *it1+d[i]-a[idx];
                ans = min(ans, max(res-hm1, hm1));
                // cout << "hm1: " << hm1 << " ans: " << ans << endl;
            }
            auto it2 = lower_bound(f, f+K, t2);
            if (it2 != f+K) {
                ll hm2 = *it2+d[i]-a[idx];
                ans = min(ans, max(res-hm2, hm2));
                // cout << "hm2: " << hm2 << " ans: " << ans << endl;
            }
            if (it2 != f) {
                it2--;
                ll hm2 = *it2+d[i]-a[idx];
                ans = min(ans, max(res-hm2, hm2));
                // cout << "hm2: " << hm2 << " ans: " << ans << endl;
            }
            // cout << "i: " << i << " ans: " << ans << endl;
        }
        // cout << "ans: " << ans << endl;
        s.erase(*s.begin());
        s.insert(res-ans);
        s.insert(ans);
        cout << *s.begin() << endl;
    }
    return 0;
}