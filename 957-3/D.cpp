#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M, K;
char a[200005];
int b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        string s; cin >> s;
        a[0] = 'L';
        a[N+1] = 'L';
        for (int i = 0; i < N; i++) {
            a[i+1] = s[i];
        }
        b[0] = 0;
        for (int i = 1; i <= N+1; i++) {
            b[i] = INT_MAX;
        }
        for (int i = 0; i <= N; i++) {
            if (b[i] == INT_MAX) continue;
            if (a[i] == 'L') {
                for (int j = 1; j <= M; j++) {
                    if (i+j > N+1) break;
                    if (a[i+j] == 'L') {
                        b[i+j] = min(b[i+j], b[i]);
                    }
                    if (a[i+j] == 'W') {
                        b[i+j] = min(b[i+j], b[i]+1);
                    }
                }
                if (i+1 <= N+1 && a[i+1] == 'W') {
                    b[i+1] = min(b[i+1], b[i]+1);
                }
            } else if (a[i] == 'W') {
                if (i+1 <= N+1 && a[i+1] == 'W') {
                    b[i+1] = min(b[i+1], b[i]+1);
                }
                if (i+1 <= N+1 && a[i+1] == 'L') {
                    b[i+1] = min(b[i+1], b[i]);
                }
            }
        }
        cout << (b[N+1]<=K ? "YES" : "NO") << "\n";
    }
    return 0;
}