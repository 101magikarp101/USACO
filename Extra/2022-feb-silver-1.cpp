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

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int N;
vector<int> adj[502];
bool vis[502];

bool dfs(int n, int t) {
    vis[n] = true;
    for (int i : adj[n]) {
        if (i == t) {
            return true;
        }
        if (!vis[i]) {
            bool res = dfs(i, t);
            if (res) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (x == i) {
                flag = false;
            }
            if (flag) {
                adj[i].push_back(x);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        bool flag = true;
        int ans = i;
        for (int j : adj[i]) {
            bool res = dfs(j, i);
            if (res) {
                ans = j;
                flag = false;
                break;
            }
        }
        cout << ans << endl;
    }
}