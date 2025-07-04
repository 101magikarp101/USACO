#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M, K;
int a[200005];
int b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        map<int, int> mb;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> b[i];
            mb[b[i]]++;
        }
        int ans = 0;
        int res = 0;
        map<int, int> ma;
        for (int i = 0; i < M; i++) {
            ma[a[i]]++;
            if (ma[a[i]] <= mb[a[i]]) {
                res++;
            }
        }
        if (res >= K) ans++;
        for (int i = M; i < N; i++) {
            ma[a[i-M]]--;
            if (ma[a[i-M]] < mb[a[i-M]]) {
                res--;
            }
            ma[a[i]]++;
            if (ma[a[i]] <= mb[a[i]]) {
                res++;
            }
            if (res >= K) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}