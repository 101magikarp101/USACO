#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
public:
    int to;
    long long cost, reward;

    Edge(int to, long long cost, long long reward) : to(to), cost(cost), reward(reward) {}
};

struct Node {
public:
    int node;
    long long cur;

    Node(int node, long long cur) : node(node), cur(cur) {}
};

vector<vector<Edge>> arr;
vector<long long> dists;
queue<Node> q;

bool solve(long long x) {
    q.clear();
    q.push(Node(0, x));
    fill(dists.begin(), dists.end(), numeric_limits<long long>::min());
    while (!q.empty()) {
        Node p = q.front();
        q.pop();
        if (p.node == arr.size() - 1) return true;
        for (Edge& e : arr[p.node]) {
            if (e.cost < e.reward) {
                if (p.cur >= e.cost) return true;
            } else {
                if (p.cur >= e.cost && dists[e.to] < e.reward + p.cur - e.cost) {
                    dists[e.to] = e.reward + p.cur - e.cost;
                    q.push(Node(e.to, e.reward + p.cur - e.cost));
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    arr.resize(n);
    dists.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c, r;
        cin >> a >> b >> c >> r;
        a--, b--;
        arr[a].emplace_back(b, c, r);
        arr[b].emplace_back(a, c, r);
    }

    long long l = 0;
    long long r = 100000000000005LL;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (solve(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << "\n";
    return 0;
}