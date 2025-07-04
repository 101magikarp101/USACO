#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, C, K;
string s;
int a[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> C >> K;
        cin >> s;
        for (int i = 0; i < N; i++) {
            a[i] = s[i]-'A';
        }
        vt<int> cnt(C,0);
        vt<bool> good(1<<C,1);
        for (int i = 0; i < K; i++) {
            cnt[a[i]]++;
        }
        for (int i = K; i < N; i++) {
            ll mask = (1<<C)-1;
            for (int j = 0; j < C; j++) {
                if (cnt[j]>0) {
                    mask ^= (1<<j);
                }
            }
            good[mask] = 0;
            cnt[a[i-K]]--;
            cnt[a[i]]++;
            // cout << "mask: " << bitset<8>(mask) << "\n";
        }
        ll mask = (1<<C)-1;
        for (int i = 0; i < C; i++) {
            if (cnt[i]>0) {
                mask ^= (1<<i);
            }
        }
        good[mask] = 0;
        // cout << "mask: " << bitset<8>(mask) << "\n";
        for (ll m = (1<<C)-1; m >= 1; m--) {
            if (good[m]) continue;
            for (int i = 0; i < C; i++) {
                if (m&(1<<i)) {
                    good[m^(1<<i)] = 0;
                }
            }
        }
        // cout << "good: ";
        // for (int i = 0; i < 1<<C; i++) {
        //     cout << good[i] << " ";
        // }
        // cout << "\n";
        ll ans = C+1;
        for (int m = 1; m < 1<<C; m++) {
            if (good[m] && (m>>a[N-1])&1) {
                ll cnt = 0;
                for (int i = 0; i < C; i++) {
                    if (m&(1<<i)) {
                        cnt++;
                    }
                }
                ans = min(ans,cnt);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}