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

struct point {
    int c, t, id;
};

struct state {
    int x, y, c1, c2;
};

int N;
point a[251][251];
bool vis[251][251];
vt<map<int, vt<int>>> adj;
vt<int> cols;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool good (int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

void fill(int i, int j, int id) {
    vt<pii> v;
    queue<pii> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        v.push_back(p);
        for (int k = 0; k < 4; k++) {
            int ni = p.x+dx[k];
            int nj = p.y+dy[k];
            if (good(ni, nj) && !vis[ni][nj] && a[ni][nj].c == a[i][j].c) {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
    for (pii p : v) {
        a[p.x][p.y].t = v.size();
        a[p.x][p.y].id = id;
    }
    cols.push_back(a[i][j].c);
}

set<int> fill2(int i, int j) {
    set<int> s;
    queue<pii> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = p.x+dx[k];
            int nj = p.y+dy[k];
            if (good(ni, nj) && !vis[ni][nj] && a[ni][nj].c == a[i][j].c) {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
            if (good(ni, nj) && a[ni][nj].id != a[i][j].id) {
                s.insert(a[ni][nj].id);
            }
        }
    }
    return s;
}

int dfs(int n, int c1, int c2) {
    int res = 0;
    queue<pii> q;
    q.push({n, c1});
    vt<vt<bool>> vis2(251, vt<bool>(251));
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        res++;
        for (int x : adj[
    }
}

int solve(int n) {
    int res = 0;
    for (auto it : adj[n]) {
        res = max(res, dfs(n, cols[n], it.first));
    }
    return res;
}

int main() {
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j].c;
        }
    }
    int id = 0;
    int ans1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) {
                fill(i, j, id++);
                ans1 = max(ans1, a[i][j].t);
            }
        }
    }
    adj.resize(id);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            set<int> s = fill2(i, j);
            for (int x : s) {
                adj[a[i][j].id][cols[x]].push_back(x);
            }
        }
    }
    int ans2 = 0;
    for (int i = 0; i < id; i++) {
        int res = solve(i);
        ans2 = max(ans2, res);
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}