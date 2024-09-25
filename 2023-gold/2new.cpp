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
#include <functional>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

struct edge;

struct node {
    ll val;
    vector<edge> out = {};
    ll in = 0;
};

struct edge {
    ll to;
    ll w;
};

struct path {
    ll l;
    ll sum;
};

struct state {
    ll d, s, t; //depth, sum, time
    edge e; //next edge
};

ll N, M;
node nodes[200005];
path paths[200005];
state best[200005];
ll times[200005];

int main() {
    cin >> N >> M;
    for (ll i = 0; i < M; i++) {
        ll a, b, w; cin >> a >> b >> w;
        nodes[a].in++;
        nodes[b].out.push_back({ a, w });
    }
    for (ll i = 1; i <= N; i++) {
        sort(nodes[i].out.begin(), nodes[i].out.end(), [](edge a, edge b) {
            return a.w < b.w;
            });
        paths[i].l = -1;
        paths[i].sum = 0;
    }
    priority_queue<state, vector<state>, function<bool(state, state)>> pq([](state a, state b) {
        if (a.d == b.d) {
            if (a.e.w == b.e.w) {
                return a.t > b.t;
            }
            return a.e.w > b.e.w;
        }
        return a.d > b.d;
        });
    for (ll i = 1; i <= N; i++) {
        if (nodes[i].in == 0) {
            paths[i].l = 0;
            paths[i].sum = 0;
            for (edge e : nodes[i].out) {
                pq.push({ 1, e.w, 0, e });
            }
        }
    }
    ll time = 0;
    while (!pq.empty()) {
        state s = pq.top();
        time++;
        nodes[s.e.to].in--;
        // cout << "in: " << s.e.to << " " << nodes[s.e.to].in << endl;
        // cout << "s: " << s.d << " " << s.s << " " << s.t << " " << s.e.to <<" " << s.e.w << endl;
        pq.pop();
        if (paths[s.e.to].l != -1) {
            if (paths[s.e.to].l < s.d) {
                paths[s.e.to].l = s.d;
                paths[s.e.to].sum = s.s;
                best[s.e.to] = s;
                times[s.e.to] = time;
            }
        }
        else {
            paths[s.e.to].l = s.d;
            paths[s.e.to].sum = s.s;
            best[s.e.to] = s;
            times[s.e.to] = time;
        }
        if (nodes[s.e.to].in == 0) {
            for (edge e : nodes[s.e.to].out) {
                pq.push({best[s.e.to].d + 1, best[s.e.to].s + e.w, times[s.e.to], e});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << paths[i].l << " " << paths[i].sum << endl;
    }
}