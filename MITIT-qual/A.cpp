#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
map<ll, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        m.clear();
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            set<int> s = {a, b, c};
            vt<int> v(s.begin(), s.end());
            ll x = 0;
            for (int j = 0; j < 3; j++) {
                x = x * 1000000LL + v[j];
            }
            m[x]++;
        }
        vt<int> ans(N+1);
        for (int i = 1; i <= N; i++) {
            ans[i] = 0;
        }
        bool good = false;
        for (auto i : m) {
            if (i.second == 0) continue;
            // cout << i.first << " " << i.second << "\n";
            int a = i.first / 1000000000000LL;
            int b = i.first / 1000000LL % 1000000LL;
            int c = i.first % 1000000LL;
            int tot = i.second;
            if (c!=0) {
                tot += m[a * 1000000000000LL + b * 1000000LL];
                tot += m[a * 1000000000000LL + c * 1000000LL];
                tot += m[b * 1000000000000LL + c * 1000000LL];
                tot += m[a * 1000000000000LL];
                tot += m[b * 1000000000000LL];
                tot += m[c * 1000000000000LL];
            } else if (b!=0) {
                tot += m[a * 1000000000000LL];
                tot += m[b * 1000000000000LL];
            }
            if (tot%2==0) continue;
            ans[a] = 1;
            ans[b] = 1;
            ans[c] = 1;
            cout << "YES" << "\n";
            for (int j = 1; j <= N; j++) {
                cout << ans[j] << " ";
            }
            cout << "\n";
            good = true;
            break;
        }
        if (good) continue;
        cout << "NO" << "\n";
    }
    return 0;
}