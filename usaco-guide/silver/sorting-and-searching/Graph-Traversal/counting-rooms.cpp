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
#define BIG 1000000000000

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
int grid[1001][1001];
bool visited[1001][1001];

bool isValid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void floodfill(int i, int j) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (isValid(x, y) && !visited[x][y] && grid[x][y] == 0) {
            floodfill(x, y);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j] = 1;
            } else if (c == '.') {
                grid[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] == 0) {
                floodfill(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}