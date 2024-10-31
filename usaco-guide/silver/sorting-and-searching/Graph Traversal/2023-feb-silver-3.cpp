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
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

struct flight {
    ll t1, t2, d;
};

ll N, M;
vector<flight> flights[200005];
ll del[200005];
ll ans[200005];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        flights[a].push_back({b, d, c});
    }
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        del[i] = a;
    }
    for (int i = 1; i <= N; i++) {
        sort(flights[i].begin(), flights[i].end(), [](flight a, flight b) {
            return a.t1 < b.t1;
        });
    }
    // cout << "flights: " << endl;
    // for (int i = 1; i <= N; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < flights[i].size(); j++) {
    //         cout << flights[i][j].t1 << " " << flights[i][j].t2 << " " << flights[i][j].d << " | ";
    //     }
    //     cout << endl;
    // }
    memset(ans, -1, sizeof(ans));
    priority_queue<pll> pq; // {time, node}
    pq.push({0, 1});
    bool first = true;
    while (!pq.empty()) {
        pll cur = pq.top();
        pq.pop();
        // cout << "cur: " << cur.first << " " << cur.second << endl;
        if (ans[cur.second] == -1) {
            ans[cur.second] = cur.first;
        } else {
            if (cur.first >= ans[cur.second]) continue;
            ans[cur.second] = cur.first;
        }
        ll t = cur.first+(first ? 0 : del[cur.second]);
        first = false;
        for (int i = flights[cur.second].size()-1; i >= 0; i--) {
            flight f = flights[cur.second][i];
            if (f.t1 < t) break;
            pq.push({f.t2, f.d});
            flights[cur.second].pop_back();
        } 
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}