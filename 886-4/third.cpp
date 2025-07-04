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
    int val;
    ll x = NULL;
    vector<pair<int, ll>> adj;
};

int T, N, M;
node arr[200001];
bool visited[200001];

bool check(node a) {
    while (a.adj.size() > 0) {
        if (arr[a.adj.back().first].x == NULL) {
            arr[a.adj.back().first].x = a.x - a.adj.back().second;
            if (!check(arr[a.adj.back().first])) {
                return false;
            }
        } else {
            if (arr[a.adj.back().first].x != a.x - a.adj.back().second) {
                return false;
            }
        }
        a.adj.pop_back();
    }
    visited[a.val] = true;
    return true;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            arr[i] = node();
            arr[i].val = i;
        }
        for (int i = 0; i < M; i++) {
            int a, b;
            ll d;
            cin >> a >> b >> d;
            arr[a].adj.push_back(make_pair(b, d));
            arr[b].adj.push_back(make_pair(a, -d));
        }
        bool flag = false;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                arr[i].x = 0;
                if (!check(arr[i])) {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
            }
        }
        // cout << "arr: " << endl;
        // for (int i = 1; i <= N; i++) {
        //     cout << arr[i].x << " ";
        // }
        if (!flag) {
            cout << "YES" << endl;
        }
        memset(visited, false, sizeof(visited));
    }
}