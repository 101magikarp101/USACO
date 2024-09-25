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

struct edge;

struct node {
    ll val;
    vector<edge> out;
    vector<edge> in;
};

struct edge {
    ll to;
    ll w;
};

struct path {
    ll l;
    ll sum;
};

ll N, M;
node nodes[200005];
path paths[200005];
ll nexts[200005];

void run(int n) {
    if (paths[n].l != -1) {
        return;
    }
    paths[n].l = 0;
    paths[n].sum = 0;
    ll blen = -1;
    vector<edge> bedges;
    for (edge e : nodes[n].out) {
        run(e.to);
        if (paths[e.to].l+1 > blen) {
            bedges.clear();
            bedges.push_back(e);
            blen = paths[e.to].l+1;
        } else if (paths[e.to].l+1 == blen) {
            bedges.push_back(e);
        }
    }
    if (bedges.empty()) {
        paths[n].l = 0;
        paths[n].sum = 0;
    }
    for (int i = 1; i < bedges.size(); i++) {
        if (bedges[i].w > bedges[0].w) {
            bedges.erase(bedges.begin()+i);
            i--;
        }
    }
    if (!bedges.empty()) {
        ll best;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll a, b, w; cin >> a >> b >> w;
        nodes[a].out.push_back({b, w});
        nodes[b].in.push_back({a, w});
    }
    for (int i = 1; i <= N; i++) {
        sort(nodes[i].out.begin(), nodes[i].out.end(), [](edge a, edge b) {
            return a.w < b.w;
        });
        paths[i].l = -1;
        paths[i].sum = 0;
        nexts[i] = -1;
    }
    for (int i = 1; i <= N; i++) {
        if (nodes[i].in.size() == 0) {
            run(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << paths[i].l << " " << paths[i].sum << endl;
    }
}