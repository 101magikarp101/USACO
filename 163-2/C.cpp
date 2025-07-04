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
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;
char grid[2][200005];
bool vis[2][200005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool good (int i, int j) {
    return i>=0 && i<2 && j>=0 && j<N;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                vis[i][j] = false;
            }
        }
        queue<pii> q;
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            pii u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ni = u.x+dx[i];
                int nj = u.y+dy[i];
                if (good(ni, nj)) {
                    if (grid[ni][nj]=='<') {
                        nj--;
                    } else {
                        nj++;
                    }
                    if (good(ni, nj) && !vis[ni][nj]) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
        if (vis[1][N-1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}