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

using namespace std;

struct node {
    double val = 0;
    int v[2] = {0, 0}; //a + b*x
    bool done = false;
    vector<pair<int, int>> ch;
};

int N, M;
node* nodes[100001];
bool vis[100001];
bool vis1[100001];
vector<pair<int, int>> vec;

//0 -> impossible, 1 -> possible, 2 -> possible with no constraints
pair<int, double> check(int id, int prev[]) {
    node* cur = nodes[id];
    if (cur->done) {
        // cout << "a: " << prev[0] << " b: " << cur->v[0] << " c: " << prev[1] << " d: " << cur->v[1] << endl;
        if (cur->v[0] == prev[0] && cur->v[1] == prev[1]) {
            return {2, 0};
        } else if (cur->v[1] == prev[1]) {
            return {0, 0};
        } else {
            return {1, (double)(prev[0]-cur->v[0])/(cur->v[1]-prev[1])};
        }
    }
    cur->done = true;
    cur->v[0] = prev[0];
    cur->v[1] = prev[1];
    // cout << "id: " << id << " prev: " << prev[0] << " " << prev[1] << endl;
    for (auto i : cur->ch) {
        auto res = check(i.first, new int[2]{i.second-cur->v[0], -cur->v[1]});
        if (res.first <= 1) {
            return res;
        }
    }
    return {2, 0};
}

pair<bool, double> fill(int id, double x, double sum) {
    node* cur = nodes[id];
    if (vis[id]) {
        if (abs(cur->val-x) <= 1e-6) {
            return {true, sum};
        } else {
            return {false, 0};
        }
    }
    vis[id] = true;
    cur->val = x;
    sum += abs(x);
    // cout << "id: " << id << " x: " << x << endl;
    for (auto i : cur->ch) {
        auto res = fill(i.first, i.second-x, sum);
        if (!res.first) {
            return {false, 0};
        } else {
            sum = res.second;
        }
    }
    return {true, sum};
}

pair<int, int> get(int id, pair<int, int> prev) {
    node* cur = nodes[id];
    if (vis1[id]) {
        return prev;
    }
    prev.first += cur->v[0];
    prev.second += cur->v[1];
    vis1[id] = true;
    // cout << "id: " << id << " prev: " << prev.first << " " << prev.second << endl;
    if (cur->v[1] != 0) vec.push_back({cur->v[0], cur->v[1]});
    for (auto i : cur->ch) {
        auto res = get(i.first, prev);
        prev = res;
    }
    return prev;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (nodes[a] == NULL) {
            nodes[a] = new node();
        }
        if (nodes[b] == NULL) {
            nodes[b] = new node();
        }
        nodes[a]->ch.push_back({b, c});
        nodes[b]->ch.push_back({a, c});
    }
    vector<pair<int, double>> v;
    int total[2] = {0, 0};
    double sum = 0;
    for (int i = 1; i <= N; i++) {
        if (nodes[i] == NULL) {
            continue;
        }
        if (!vis[i]) {
            auto res = check(i, new int[2]{0, 1});
            // cout << "res: " << res.first << " " << res.second << endl;
            if (res.first == 0) {
                cout << "NO" << endl;
                return 0;
            } else if (res.first == 1) {
                auto res1 = fill(i, res.second, 0);
                if (!res1.first) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    sum += res1.second;
                }
            } else {
                auto res1 = get(i, {0, 0});
                sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
                    return (double)-(a.first/a.second) < (double)-(b.first/b.second);
                });
                double x = 0;
                double s = 0;
                for (auto i : vec) {
                    s -= abs(i.second);
                }
                for (auto i : vec) {
                    s += 2*abs(i.second);
                    if (s >= 0) {
                        x = (double)-i.first/i.second;
                        break;
                    }
                }
                fill(i, x, 0);
                vec.clear();
            }
        }
    }
    // cout << "v: ";
    // for (auto i : v) {
    //     cout << i.first << " ";
    // }
    // cout << endl;
    // cout << "total: " << total[0] << " " << total[1] << endl;
    // cout << "sum: " << sum << endl;
    cout << "YES" << endl;
    for (int i = 1; i <= N; i++) {
        if (nodes[i] == NULL) {
            cout << 0 << " ";
        } else {
            cout << nodes[i]->val << " ";
        }
    }
    cout << endl;

}