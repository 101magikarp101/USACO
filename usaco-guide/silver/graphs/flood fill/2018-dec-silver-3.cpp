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
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N, K;
int a[100][10];
bool vis[100][10];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 , -1};

bool good(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < 10;
}

void fall() {
    for (int j = 0; j < 10; j++) {
        int cur = N-1;
        for (int i = N-1; i >= 0; i--) {
            if (a[i][j] != 0) {
                a[cur][j] = a[i][j];
                cur--;
            }
        }
        for (int i = cur; i >= 0; i--) {
            a[i][j] = 0;
        }
    }
}

bool iterate() {
    memset(vis, false, sizeof(vis));
    bool done = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] != 0) {
                if (!vis[i][j]) {
                    vis[i][j] = true;
                    int c = a[i][j];
                    queue<pii> q;
                    q.push({i, j});
                    vector<pii> v;
                    while (!q.empty()) {
                        pii cur = q.front();
                        v.push_back(cur);
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = cur.first+dx[k];
                            int ny = cur.second+dy[k];
                            if (!good(nx, ny)) continue;
                            if (a[nx][ny] != c) continue;
                            if (vis[nx][ny]) continue;
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                    if (v.size() >= K) {
                        done = false;
                        for (pii p : v) {
                            a[p.first][p.second] = 0;
                        }
                    }
                }
            }
        }
    }
    return done;
}

int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            a[i][j] = s[j]-'0';
        }
    }
    while (true) {
        bool res = iterate();
        if (res) break;
        fall();
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}