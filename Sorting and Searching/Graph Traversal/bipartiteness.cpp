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

#define ll long long
#define BIG 1000000000000

using namespace std;

int N;
vector<int> adj[100001];
int vals[100001];
map<int, int> freq;
bool visited[100001];
bitset<100001> colors;

void dfs(int node, int color) {
    freq[color]++;
    visited[node] = true;
    colors[node] = color;
    //cout << "node: " << node << " color: " << color << " freq[color]: " << freq[color] << endl;
    color = 1 - color;
    for (int i : adj[node]) {
        if (!visited[i]) {
            dfs(i, color);
        }
    }
}

int main() {
    freq[0] = 0;
    freq[1] = 0;
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vals[a]++;
        vals[b]++;
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (colors[i] == 0) {
            ans += freq[1] - vals[i];
        } else {
            ans += freq[0] - vals[i];
        }
    }
    cout << ans/2 << endl;
}