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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
int grid[1001][1001];
bool visited[1001][1001];

bool isValid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

pair<int, int> floodfill(int i, int j) {
    int area = 1;
    int peri = 0;
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (isValid(x, y) && !visited[x][y] && grid[x][y] == 1) {
            pair<int, int> res = floodfill(x, y);
            area += res.first;
            peri += res.second;
        } else if ((isValid(x, y) && grid[x][y] == 0) || !isValid(x, y)) {
            peri++;
        }
    }
    return {area, peri};
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j] = 1;
            } else if (c == '.') {
                grid[i][j] = 0;
            }
        }
    }
    int area = -1;
    int peri = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                pair<int, int> res = floodfill(i, j);
                if (res.first > area) {
                    area = res.first;
                    peri = res.second;
                } else if (res.first == area) {
                    peri = min(peri, res.second);
                }
            }
        }
    }
    cout << area << " " << peri << endl;
}
