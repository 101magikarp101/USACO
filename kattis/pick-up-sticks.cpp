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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    int in;
    vt<int> adj;
};

int N, M;
node nodes[1000003];
bool vis[1000003];

int main () {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        nodes[a].adj.push_back(b);
        nodes[b].in++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (nodes[i].in == 0) q.push(i);
    }
    vt<int> ans;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (int i : nodes[cur].adj) {
            nodes[i].in--;
            if (nodes[i].in == 0) {
                if (vis[i]) {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                } else {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
    }
    if (ans.size() != N) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i : ans) {
        cout << i << endl;
    }
}