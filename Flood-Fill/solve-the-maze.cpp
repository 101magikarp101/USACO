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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007
#define INT_MAX 2147483647

using namespace std;

int T, N, M;
char a[51][51];
bool vis[51][51];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool good(int i, int j) {
    return i >= 1 && i <= N && j >= 1 && j <= M;
}

int main() {
    cin >> T;
    while (T--) {
        memset(vis, 0, sizeof(vis));
        cin >> N >> M;
        bool hasG = false;
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= M; j++) {
                a[i][j] = s[j-1];
                if (a[i][j] == 'G') hasG = true;
            }
        }
        if (!hasG) {
            cout << "Yes" << endl;
            continue;
        }
        bool flag = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (a[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if (!good(nx, ny)) continue;
                        if (a[nx][ny] == '.') {
                            a[nx][ny] = '#';
                        } else if (a[nx][ny] == 'G') {
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) {
            cout << "No" << endl;
            continue;
        }
        if (a[N][M] == '#') {
            cout << "No" << endl;
            continue;
        }
        queue<pii> q;
        q.push({N, M});
        vis[N][M] = true;
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.first+dx[i];
                int ny = cur.second+dy[i];
                if (good(nx, ny) && !vis[nx][ny] && a[nx][ny] != '#') {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (a[i][j] == 'G' && !vis[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (!ok) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}