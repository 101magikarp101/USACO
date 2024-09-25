#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
int a[505][505], b[505][505];

int pl(int x) {
    return (x+1)%3;
}

int mi(int x) {
    return (x+2)%3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            string s; cin >> s;
            for (int j = 1; j <= M; j++) {
                a[i][j] = s[j-1]-'0';
            }
        }
        for (int i = 1; i <= N; i++) {
            string s; cin >> s;
            for (int j = 1; j <= M; j++) {
                b[i][j] = s[j-1]-'0';
            }
        }
        for (int i = 1; i <= N-1; i++) {
            for (int j = 1; j <= M-1; j++) {
                if ((a[i][j]-b[i][j]+3)%3 == 1) {
                    a[i][j] = mi(a[i][j]);
                    a[i+1][j] = pl(a[i+1][j]);
                    a[i][j+1] = pl(a[i][j+1]);
                    a[i+1][j+1] = mi(a[i+1][j+1]);
                } else if ((a[i][j]-b[i][j]+3)%3 == 2) {
                    a[i][j] = pl(a[i][j]);
                    a[i+1][j] = mi(a[i+1][j]);
                    a[i][j+1] = mi(a[i][j+1]);
                    a[i+1][j+1] = pl(a[i+1][j+1]);
                }
            }
        }
        bool ok = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (a[i][j] != b[i][j]) {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}