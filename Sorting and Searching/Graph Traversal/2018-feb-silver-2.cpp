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
#define INT_MAX 2147483647

using namespace std;

int N, B;
int arr[251];
vector<pair<int, int>> adj[251]; // <boots, <next, bootid>>
pair<int, int> boots[251];
int mins[251];

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    }
};

void floodfill(int node, int bootid) {
    // cout << "visiting " << node << " with bootid " << bootid << endl;
    if (node == N-1) {
        return;
    }
    int ans = INT_MAX;
    for (int i = 0; i < adj[node].size(); i++) {
        // cout << "checking " << adj[node][i].first << " with bootid " << adj[node][i].second << endl;
        // cout << "mins[" << adj[node][i].first << "] = " << mins[adj[node][i].first] << endl;
        if (adj[node][i].second >= bootid && mins[adj[node][i].first] > adj[node][i].second) {
            mins[adj[node][i].first] = adj[node][i].second;
            floodfill(adj[node][i].first, adj[node][i].second);
            bootid = adj[node][i].second;
        }
    }
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    for (int i = 0; i < 251; i++) {
        mins[i] = INT_MAX;
    }
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }
    for (int i = 0; i < B; i++) {
        int a, b;
        cin >> a >> b;
        boots[i] = make_pair(a, b);
    }
    for (int i = 0; i < B; i++) {
        for (int j = N-1; j >= 0; j--) {
            if (arr[j] <= boots[i].first) {
                for (int k = j-1; k >= max(0, j-boots[i].second); k--) {
                    adj[k].push_back(make_pair(j, i));
                }
            }
        }
    }
    // cout << "adj: " << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < adj[i].size(); j++) {
    //         cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ") ";
    //     }
    //     cout << endl;
    // }
    floodfill(0, 0);
    cout << mins[N-1] << endl;
}