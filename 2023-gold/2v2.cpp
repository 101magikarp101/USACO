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
vector<ll> routes[200005];

void run1(int n) {
    if (paths[n].l != -1) {
        return;
    }
    paths[n].l = 0;
    paths[n].sum = 0;
    ll bnode = -1;
    ll blen = -1;
    ll bsum = -1;
    for (edge e : nodes[n].out) {
        run1(e.to);
        if (paths[e.to].l+1 > blen) {
            bnode = e.to;
            blen = paths[e.to].l + 1;
            bsum = paths[e.to].sum + e.w;
        }
    }
    if (bnode != -1) {
        paths[n].l = blen;
        paths[n].sum = bsum;
    } else {
        paths[n].l = 0;
        paths[n].sum = 0;
    }
}

void run2(int n) {
    if (paths[n].l != -1) {
        return;
    }
    paths[n].l = 0;
    paths[n].sum = 0;
    ll blen = -1;
    vector<edge> bedges;
    for (edge e : nodes[n].out) {
        run2(e.to);
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
        routes[n] = {};
    }
    for (int i = 1; i < bedges.size(); i++) {
        if (bedges[i].w > bedges[0].w) {
            bedges.erase(bedges.begin()+i);
            i--;
        }
    }
    if (!bedges.empty()) {
        ll best;
        for (int i = 0; i < routes[bedges[0].to].size(); i++) {
            best = LLONG_MAX;
            if (bedges.size() == 1) {
                break;
            }
            for (int j = 0; j < bedges.size(); j++) {
                best = min(best, routes[bedges[j].to][i]);
            }
            // cout << "best: " << best << endl;
            // cout << "bedges: ";
            // for (edge e : bedges) {
            //     cout << e.to << " " << e.w << " | ";
            // }
            // cout << endl;
            //remove all routes that are not best
            for (int j = 0; j < bedges.size(); j++) {
                if (routes[bedges[j].to][i] != best) {
                    bedges.erase(bedges.begin()+j);
                    j--;
                }
            }
        }
        paths[n].l = blen;
        paths[n].sum = bedges[0].w + paths[bedges[0].to].sum;
        routes[n].push_back(bedges[0].w);
        routes[n].insert(routes[n].end(), routes[bedges[0].to].begin(), routes[bedges[0].to].end());
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
    }
    bool flag = (N <= 5000 && M <= 5000);
    for (int i = 1; i <= N; i++) {
        if (nodes[i].in.size() == 0) {
            if (flag) {
                run2(i);
            } else {
                run1(i);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << paths[i].l << " " << paths[i].sum << endl;
    }
}