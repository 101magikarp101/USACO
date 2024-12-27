#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[21][21], b[21][21];
vt<ll> s[21];
int stop = 0;
int ans = 0;

void dfs1(int x, int y, ll v) {
    if (x+y==stop) {
        s[x].push_back(v);
        return;
    }
    dfs1(x+1,y,v|(1LL<<a[x][y]));
    dfs1(x,y+1,v|(1LL<<b[x][y]));
    dfs1(x+1,y,v);
    dfs1(x,y+1,v);
}

void dfs2(int x, int y, ll v) {
    if (x+y==stop) {
        for (; ans < 2*N-2; ans++) {
            ll z = ((2LL<<ans)-1)&(~v);
            if (!binary_search(s[x].begin(),s[x].end(),z)) {
                break;
            }
        }
        return;
    }
    if (x>0) {
        dfs2(x-1,y,v|(1LL<<a[x-1][y]));
    }
    if (y>0) {
        dfs2(x,y-1,v|(1LL<<b[x][y-1]));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    cin >> T;
    while (T--) {
        cin >> N;
        stop = 2*N/3;
        ans = 0;
        for (int i = 0; i < N; i++) {
            s[i].clear();
        }
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N-1; j++) {
                cin >> b[i][j];
            }
        }
        dfs1(0,0,0);
        for (int i = 0; i < N; i++) {
            sort(s[i].begin(),s[i].end());
            s[i].erase(unique(s[i].begin(),s[i].end()),s[i].end());
        }
        dfs2(N-1,N-1,0);
        cout << ans << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;
    return 0;
}