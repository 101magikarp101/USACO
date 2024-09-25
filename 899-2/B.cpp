#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
bool a[51][51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        set<int> s1;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            for (int j = 1; j <= 50; j++) {
                a[i][j] = 0;
            }
            for (int j = 0; j < x; j++) {
                int y; cin >> y;
                s1.insert(y);
                a[i][y] = 1;
            }
        }
        int ans = -1;
        for (int i = 1; i <= 50; i++) {
            set<int> s;
            for (int j = 0; j < N; j++) {
                if (a[j][i] == 0) {
                    for (int k = 1; k <= 50; k++) {
                        if (a[j][k] == 1) {
                            s.insert(k);
                        }
                    }
                }
            }
            if (s.size() != s1.size()) ans = max(ans, (int)s.size());
        }
        cout << ans << "\n";
    }
    return 0;
}