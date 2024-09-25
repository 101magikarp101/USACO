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
    int col = -1;
    vt<int> adj;
};

int N, K;
node nodes[100005];
ll dp[100005][3];

ll mult(ll a, ll b) {
    return (a * b) % MOD2;
}

ll add(ll a, ll b) {
    return (a + b) % MOD2;
}

ll solve(int n, int p) {
    ll ans = 1;
}

int main () {
    cin >> N >> K;
    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].adj.push_back(y);
        nodes[y].adj.push_back(x);
    }
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        y--;
        nodes[x].col = y;
        for (int j = 0; j < nodes[x].adj.size(); j++) {
            nodes[nodes[x].adj[j]].bad[y] = true;
        }
    }
    ll ans = solve(1, 0);
    cout << ans << endl;
}