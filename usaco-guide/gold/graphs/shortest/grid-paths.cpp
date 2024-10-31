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

struct state {
    int x, y, dir;
    string s;
    ll vis;
};

int N = 7;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string dc[] = {"R", "D", "L", "U"};
vt<string> res;

bool good (int x, int y, ll vis) {
    return x>=0 && x<N && y>=0 && y<N && !(vis&(1LL<<(N*x+y)));
}

void solve(state s) {
    if (s.x==N-1 && s.y==0 && s.s.size()==N*N-1) {
        res.push_back(s.s);
        return;
    } else if (s.x==N-1 && s.y==0) {
        return;
    }
    int d1 = (s.dir+1)%4;
    int d2 = (s.dir+3)%4;
    int nx = s.x + dx[s.dir];
    int ny = s.y + dy[s.dir];
    int nx1 = s.x + dx[d1];
    int ny1 = s.y + dy[d1];
    int nx2 = s.x + dx[d2];
    int ny2 = s.y + dy[d2];
    bool g = good(nx, ny, s.vis);
    bool g1 = good(nx1, ny1, s.vis);
    bool g2 = good(nx2, ny2, s.vis);
    if (!g) {
        if (g1&&g2) return;
    }
    if (g) {
        solve({nx, ny, s.dir, s.s+dc[s.dir], s.vis^(1LL<<(N*nx+ny))});
    }
    if (g1) {
        solve({nx1, ny1, d1, s.s+dc[d1], s.vis^(1LL<<(N*nx1+ny1))});
    }
    if (g2) {
        solve({nx2, ny2, d2, s.s+dc[d2], s.vis^(1LL<<(N*nx2+ny2))});
    }
}

int main() {
    // queue<state> q;
    // q.push({0,0,0,"",1});
    // while (!q.empty()) {
    //     state cur = q.front();
    //     q.pop();
    //     // cout << "cur: " << cur.x << " " << cur.y << " " << cur.s << " " << bitset<49>(cur.vis) << endl;
    //     if (cur.x==6 && cur.y==6 && cur.s.size()==48) {
    //         res.push_back(cur.s);
    //         continue;
    //     }
    //     int nx = cur.x + dx[cur.dir];
    //     int ny = cur.y + dy[cur.dir];
    //     int nx1 = cur.x + dx[(cur.dir+1)%4];
    //     int ny1 = cur.y + dy[(cur.dir+1)%4];
    //     int nx2 = cur.x + dx[(cur.dir+3)%4];
    //     int ny2 = cur.y + dy[(cur.dir+3)%4];
    //     bool g = good(nx, ny, cur.vis);
    //     bool g1 = good(nx1, ny1, cur.vis);
    //     bool g2 = good(nx2, ny2, cur.vis);
    //     if (!g) {
    //         if (g1&&g2) continue;
    //     }
    //     if (g) {
    //         q.push({nx, ny, cur.dir, cur.s+dc[cur.dir], cur.vis|(1LL<<(7*nx+ny))});
    //     }
    //     if (g1) {
    //         q.push({nx1, ny1, (cur.dir+1)%4, cur.s+dc[(cur.dir+1)%4], cur.vis|(1LL<<(7*nx1+ny1))});
    //     }
    //     if (g2) {
    //         q.push({nx2, ny2, (cur.dir+3)%4, cur.s+dc[(cur.dir+3)%4], cur.vis|(1LL<<(7*nx2+ny2))});
    //     }
    // }
    solve({0,0,0,"",1});
    int ans = 0;
    string s; cin >> s;
    for (int i = 0; i < res.size(); i++) {
        // cout << res[i] << endl;
        bool good = true;
        for (int j = 0; j < s.size(); j++) {
            if (s[j]!='?') {
                if (s[j]!=res[i][j]) {
                    good = false;
                    break;
                }
            }
        }
        if (good) ans++;
    }
    cout << ans << endl;
    return 0;
}