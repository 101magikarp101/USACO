#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[5005];
int tot[5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vt<int> b, eat;
        b.clear();
        eat.clear();
        for (int i = 0; i <= 5000; i++) {
            tot[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            tot[a[i]]++;
        }
        // cout << "b: ";
        // for (int i = 1; i <= 5000; i++) {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= 5000; i++) {
            if (tot[i] != 0) {
                b.push_back(tot[i]);
                eat.push_back(false);
            }
        }
        int n = b.size();
        int l = 0, r = 0;
        int ans = 1;
        eat[0] = true;
        int cur = 1;
        int d = 0;
        while (true) {
            // cout << "b[r]: " << b[r] << " eat[r]: " << eat[r] << endl;
            // cout << "l: " << l << " r: " << r << " cur: " << cur << " d: " << d << endl;
            while ((b[r] != cur || eat[r]) && r < n) {
                if (!eat[r]) d++;
                r++;
            }
            if (r >= n) {
                cur++;
                if (cur > 5000) {
                    break;
                }
                r = l+1;
                d = 0;
                continue;
            }
            if (b[r] == cur) {
                if (d+1 >= cur) {
                    eat[r] = true;
                    int cnt = 0;
                    while (cnt < cur && l < n) {
                        if (!eat[l]) {
                            cnt++;
                            eat[l] = true;
                            if (cnt != cur) l++;
                            d--;
                        } else {
                            l++;
                        }
                    }
                    ans += cnt;
                    // cout << "l: " << l << " r: " << r << " cnt: " << cnt << " ans: " << ans << endl;
                    if (l >= n) {
                        break;
                    }
                    if (l >= r) {
                        r = l;
                        d = 0;
                        continue;
                    }
                } else {
                    if (!eat[r]) d++;
                    r++;
                }
            }
        }
        while (l < n) {
            if (!eat[l]) {
                ans++;
            }
            l++;
        }
        cout << ans << endl;
    }
    return 0;
}