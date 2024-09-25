#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, M;
vt<int> a[101];

int main() {
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        if (x<y) swap(x,y);
        a[x].push_back(y);
    }
    int ans[101];
    bool vis[5];
    for (int i = 1; i <= N; i++) {
        memset(vis,0,sizeof(vis));
        for (int j = 0; j < a[i].size(); j++) {
            vis[ans[a[i][j]]] = 1;
        }
        int res = 1;
        while (vis[res]) res++;
        ans[i] = res;
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}