#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, M, K;
char a[12][12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (a[j][i] == 'Y') {
                cnt++;
            }
        }
        if (cnt >= K) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}