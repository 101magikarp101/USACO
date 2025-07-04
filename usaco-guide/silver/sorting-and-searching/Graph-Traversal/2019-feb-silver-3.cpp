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

int N, M;
vector<pair<int, vector<pair<int, int>>>> nodes(100001);
bool visited[100001];

bool solve(int val, int id) {
    // cout << "id: " << id << " val: " << val << endl;
    if (nodes[id].first != -1) {
        return nodes[id].first == val;
    }
    visited[id] = true;
    nodes[id].first = val;
    for (int i = 0; i < nodes[id].second.size(); i++) {
        if (!solve(val ^ nodes[id].second[i].second, nodes[id].second[i].first)) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> N >> M;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < M; i++) {
        char d;
        int x, y;
        cin >> d >> x >> y;
        if (d == 'S') {
            nodes[x].first = -1;
            nodes[y].first = -1;
            nodes[x].second.push_back({y, 0});
            nodes[y].second.push_back({x, 0});
        } else {
            nodes[x].first = -1;
            nodes[y].first = -1;
            nodes[x].second.push_back({y, 1});
            nodes[y].second.push_back({x, 1});
        }
    }
    string s = "1";
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            if (nodes[i].first != -1) {
                s += "0";
                continue;
            }
            bool res = solve(0, i);
            if (res) {
                s += "0";
            } else {
                cout << "0" << endl;
                return 0;
            }
        }
    }
    cout << s << endl;
}
