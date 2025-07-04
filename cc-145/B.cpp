#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
string s;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        for (int i = 0; i < N; i++) {
            a[i] = s[i] - '0';
        }
        int cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] == 1) {
                cnt1++;
            } else {
                cnt0++;
            }
        }
        if (cnt1 == 0) {
            int ans = min(2, N);
            cout << ans << "\n";
            continue;
        } else if (cnt0 == 0) {
            cout << 0 << endl;
            continue;
        } else {
            int ans = (a[0]==0)+(a[N-1]==0);
            cout << ans << "\n";
        }
    }
    return 0;
}