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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct edge {
    ll u, v, w;
};

struct state {
    ll d, to, orig;
    bool operator<(const state& s) const {
        return d < s.d;
    }
    bool operator>(const state& s) const {
        return d > s.d;
    }
};

ll N,M,C,R,K;
vt<edge> adj[50005];
map<int, ll> paths[50005];

int main () {
    cin >> N >> M >> C >> R >> K;
    set<int> ans;
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({u, v, w});
        adj[v].push_back({v, u, w});
    }
    priority_queue<state, vt<state>, greater<state>> pq;
    for (int i = 1; i <= C; i++) {
        pq.push({0, i, i});
    }
    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();
        // cout << s.to << " " << s.d << endl;
        if (paths[s.to].find(s.orig) != paths[s.to].end() && paths[s.to][s.orig] <= s.d) {
            continue;
        }
        if (paths[s.to].size() >= K) {
            ll ma = 0;
            for (auto it = paths[s.to].begin(); it != paths[s.to].end(); it++) {
                ma = max(ma, it->second);
            }
            if (s.d >= ma) {
                continue;
            }
        }
        paths[s.to][s.orig] = s.d;
        for (edge e : adj[s.to]) {
            if (s.d+e.w > R) {
                continue;
            }
            pq.push({s.d+e.w, e.v, s.orig});
        }
    }
    // cout << "paths" << endl;
    // for (int i = 1; i <= N; i++) {
    //     cout << i << ": ";
    //     for (auto it = paths[i].begin(); it != paths[i].end(); it++) {
    //         cout << it->first << " " << it->second << " | ";
    //     }
    //     cout << endl;
    // }
    int tot = 0;
    for (int i =C+1; i <= N; i++) {
        if (paths[i].size() >= K) {
            tot++;
        }
    }
    cout << tot << endl;
    for (int i = C+1; i <= N; i++) {
        if (paths[i].size() >= K) {
            cout << i << endl;
        }
    }
}