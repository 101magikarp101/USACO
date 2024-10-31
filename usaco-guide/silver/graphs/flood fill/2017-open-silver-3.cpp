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

int N;
char a[20][20];
bool vis[20][20];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 , -1};

struct rect {
    int x1, y1, x2, y2;
}; // top left, bottom right

bool good(int i, int j, rect r) {
    return i >= r.x1 && i <= r.x2 && j >= r.y1 && j <= r.y2;
}

void fill(int i, int j, rect r, char c) {
    if (!good(i, j, r)) return;
    if (vis[i][j]) return;
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if (!good(nx, ny, r)) continue;
        if (vis[nx][ny]) continue;
        if (a[nx][ny] == c) fill(nx, ny, r, c);
    }
}

bool check(rect r) {
    memset(vis, false, sizeof(vis));
    map<char, int> m;
    for (int i = r.x1; i <= r.x2; i++) {
        for (int j = r.y1; j <= r.y2; j++) {
            if (!vis[i][j]) {
                m[a[i][j]]++;
                fill(i, j, r, a[i][j]);
            }
        }
    }
    if (m.size() == 2) {
        vector<int> v;
        for (auto i : m) {
            v.push_back(i.second);
        }
        sort(v.begin(), v.end());
        if (v[0] == 1 && v[1] > 1) return true;
        else return false;
    } else return false;
}

bool has (vector<rect> v, rect r) {
    for (rect i : v) {
        if (r.x1 >= i.x1 && r.x2 <= i.x2 && r.y1 >= i.y1 && r.y2 <= i.y2) return true;
    }
    return false;
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            a[i][j] = s[j];
        }
    }
    vector<rect> v;
    for (int d1 = N; d1 >= 1; d1--) {
        for (int i = 0; i+d1-1 < N; i++) {
            for (int d2 = N; d2 >= 1; d2--) {
                for (int j = 0; j+d2-1 < N; j++) {
                    if (has(v, {i, j, i+d1-1, j+d2-1})) continue;
                    if (check({i, j, i+d1-1, j+d2-1})) {
                        v.push_back({i, j, i+d1-1, j+d2-1});
                    }
                }
            }
        }
    }
    cout << v.size() << endl;
}