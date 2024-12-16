#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n = 130;
bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool solve(int sx, int sy, vector<vector<char>>& a) {
    auto start = chrono::high_resolution_clock::now();
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(n, vector<bool>(4, false)));
    int dir = 0;

    int cnt = 0;
    while (in(sx, sy)) {
        cnt++;
        if (vis[sx][sy][dir]) {
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
            cout << "cnt: " << cnt << endl;
            cout << duration << " ms" << endl;
            return true;
        }
        vis[sx][sy][dir] = true;

        int nx = sx + dx[dir];
        int ny = sy + dy[dir];

        if (in(nx, ny) && a[nx][ny] == '#') {
            dir = (dir + 1) % 4;
        } else {
            sx = nx;
            sy = ny;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "cnt: " << cnt << endl;
    cout << duration << " ms" << endl;
    return false;
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    vector<vector<char>> a(n, vector<char>(n));
    int sx = 0, sy = 0;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j];
            if (a[i][j] == '^') {
                sx = i;
                sy = j;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '.') {
                a[i][j] = '#';
                if (solve(sx, sy, a)) {
                    ++ans;
                }
                a[i][j] = '.';
            }
        }
    }

    cout << ans << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << duration << " ms" << endl;

    return 0;
}
