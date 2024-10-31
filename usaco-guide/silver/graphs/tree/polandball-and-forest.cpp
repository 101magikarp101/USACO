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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N;
vector<int> adj[10005];
bool vis[10005];

void fill (int node) {
    vis[node] = true;
    for (int i : adj[node]) {
        if (!vis[i]) {
            fill(i);
        }
    }
}

int main () {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            ans++;
            fill(i);
        }
    }
    cout << ans << endl;
}