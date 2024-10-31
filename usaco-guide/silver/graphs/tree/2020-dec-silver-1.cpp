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
vector<int> adj[100005];
bool vis[100005];

ll solve(int n) {
    if (vis[n]) return 0;
    vis[n] = true;
    if (n==1) {
        ll ans = ceil(log2(adj[n].size()+1));
        for (int i : adj[n]) {
            ans += solve(i);
        }
        ans += adj[n].size();
        // cout << "n: " << n << " ans: " << ans << endl;
        return ans;
    } else {
        if (adj[n].size() == 1) {
            // cout << "n: " << n << " ans: " << 0 << endl;
            return 0;
        } else {
            ll ans = ceil(log2(adj[n].size()));
            for (int i : adj[n]) {
                ans += solve(i);
            }
            ans += adj[n].size()-1;
            // cout << "n: " << n << " ans: " << ans << endl;
            return ans;
        }
    }
}

int main () {
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = solve(1);
    cout << ans << endl;
}