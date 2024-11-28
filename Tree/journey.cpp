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

double e(int n) {
    if (vis[n]) return 0;
    vis[n] = true;
    if (n == 1) {
        double ans = 0;
        for (int i : adj[n]) {
            ans += e(i);
        }
        ans /= adj[n].size();
        return ans+1;
    } else {
        if (adj[n].size() == 1) {
            return 0;
        } else {
            double ans = 0;
            for (int i : adj[n]) {
                ans += e(i);
            }
            ans /= adj[n].size()-1;
            return ans+1;
        }
    }
}

int main() {
    cin >> N;
    if (N==1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    double ans = e(1);
    cout << fixed << setprecision(10) << ans << endl;
}