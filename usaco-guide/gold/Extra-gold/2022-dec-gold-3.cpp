#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int N, M;
vt<int> adj[100005];
bool in[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DSU dsu(N+1);
    sort(adj+1, adj+N+1, [](vt<int> a, vt<int> b) {
        return a.size() > b.size();
    });
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j: adj[i]) {
            if (adj[i].size() >= adj[j].size()) {
                dsu.unite(i, j);
                cnt++;
            }
        }
        ans = max(ans, (ll)dsu.size(i)*cnt);
        cout << "i: " << i << " " << dsu.size(i) << " " << cnt << " " << dsu.size(i)*cnt << endl;
    }
    cout << ans << endl;
    return 0;
}