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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N;
vector<vector<int>> adj;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        adj = vector<vector<int>>(N+1);
        for (int i = 0; i < N-1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (N==1) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (adj[i].size() == 1) {
                ans++;
            }
        }
        cout << (ans+1)/2 << endl;
    }
}