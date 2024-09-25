#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N;
set<int> vis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        int tot = 0;
        for (int j = 0; j < M; j++) {
            int x; cin >> x;
            if (vis.find(x) == vis.end()) {
                tot++;
            }
            vis.insert(x);
        }
        ans = max(ans, tot);
    }
    cout << ans << endl;
    return 0;
}