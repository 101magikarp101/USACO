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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct space {
    char c;
    int i, j;
};

struct state {
    int x, y;
    int a;
};

int N;
space grid[26][26];
bool vis[26][26][19683];
int sx, sy;
string moo = "MOO";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool good(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool valid(int a) {
    vt<vt<char>> v(3, vt<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v[i][j] = (a/(int)pow(3, 3*i+j))%3;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (v[i][0] == 2 && v[i][1] == 1 && v[i][2] == 1) return true;
        if (v[0][i] == 2 && v[1][i] == 1 && v[2][i] == 1) return true;
        if (v[i][0] == 1 && v[i][1] == 1 && v[i][2] == 2) return true;
        if (v[0][i] == 1 && v[1][i] == 1 && v[2][i] == 2) return true;
    }
    if (v[0][0] == 2 && v[1][1] == 1 && v[2][2] == 1) return true;
    if (v[0][0] == 1 && v[1][1] == 1 && v[2][2] == 2) return true;
    if (v[0][2] == 2 && v[1][1] == 1 && v[2][0] == 1) return true;
    if (v[0][2] == 1 && v[1][1] == 1 && v[2][0] == 2) return true;
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3*N; j+=3) {
            if (s[j]=='#') {
                grid[i][j/3] = {'#', -1, -1};
            } else if (s[j]=='B') {
                grid[i][j/3] = {'.', -1, -1};
                sx = i;
                sy = j/3;
            } else if (s[j]=='.') {
                grid[i][j/3] = {'.', -1, -1};
            } else {
                grid[i][j/3] = {s[j], s[j+1]-'1', s[j+2]-'1'};
                // cout << "i: " << i << " j: " << j/3 << " c: " << s[j] << " i: " << s[j+1]-'1' << " j: " << s[j+2]-'1' << endl;
            }
        }
    }
    queue<state> q;
    q.push({sx, sy, 0});
    vis[sx][sy][0] = true;
    set<int> ans;
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        // cout << "x: " << cur.x << " y: " << cur.y << " a: " << cur.a << endl;
        if (valid(cur.a)) {
            ans.insert(cur.a);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if (good(nx, ny) && grid[nx][ny].c!='#') {
                // cout << "nx: " << nx << " ny: " << ny << endl;
                int na = cur.a;
                if (grid[nx][ny].c != '.' && (cur.a/(int)pow(3, 3*grid[nx][ny].i+grid[nx][ny].j))%3 == 0) {
                    int x = (grid[nx][ny].c=='M') ? 2 : 1;
                    na += (int)pow(3, 3*grid[nx][ny].i+grid[nx][ny].j)*x;
                }
                if (!vis[nx][ny][na]) {
                    vis[nx][ny][na] = true;
                    q.push({nx, ny, na});
                }
                // cout << "con1: " << con1 << endl;
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}