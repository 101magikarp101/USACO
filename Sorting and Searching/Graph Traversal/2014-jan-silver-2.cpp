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

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
ll N, M;
ll grid[501][501];
bool visited[501][501];
vector<pair<int, int>> waypoints;

bool isValid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void floodfill(ll i, ll j, ll d) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        ll x = i + dx[k];
        ll y = j + dy[k];
        if (isValid(x, y) && !visited[x][y] && abs(grid[x][y] - grid[i][j]) <= d) {
            floodfill(x, y, d);
        }
    }
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            grid[i][j] = a;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                waypoints.push_back({i, j});
            }
        }
    }
    ll low = 0;
    ll high = 1e10;
    while (low < high) {
        memset(visited, false, sizeof(visited));
        ll mid = (low + high) / 2;
        floodfill(waypoints[0].first, waypoints[0].second, mid);
        bool ok = true;
        for (int i = 0; i < waypoints.size(); i++) {
            if (!visited[waypoints[i].first][waypoints[i].second]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}