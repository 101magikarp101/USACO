#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[5005];
int p[5005];
vt<int> adj[5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        for (int i = 2; i <= N; i++) {
            cin >> p[i];
            adj[p[i]].push_back(i);
        }
        
    }
    return 0;
}