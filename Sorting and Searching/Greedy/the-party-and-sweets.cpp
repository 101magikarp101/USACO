#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    ll N, M;
    cin >> N >> M;
    ll h[100000], g[100000];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        ans += h[i] * M;
    }
    for (int i = 0; i < M; i++) {
        cin >> g[i];
    }
    sort(h, h + N, greater<ll>());
    sort(g, g + M);
    bool flag = false;
    for (int i = 0; i < M; i++) {
        if (i == M - 1 && !flag) {
            ans += g[i] - h[1];
        } else if (g[i] >= h[0]) {
            ans += g[i] - h[0];
            if (g[i] == h[0]) {
                flag = true;
            }
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}