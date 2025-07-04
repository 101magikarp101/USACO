#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
char a[200005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> a[j][i];
            }
        }
        int ans = 0;
        for (int i = 1; i < N-1; i++) {
            if (a[i][0] == '.' && a[i][1] == '.') {
                if (a[i-1][0]=='.'&&a[i-1][1]=='x'&&a[i+1][0]=='.'&&a[i+1][1]=='x') {
                    ans++;
                }
                else if (a[i-1][0]=='x'&&a[i-1][1]=='.'&&a[i+1][0]=='x'&&a[i+1][1]=='.') {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}