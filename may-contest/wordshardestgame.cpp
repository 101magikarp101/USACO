#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct space {
    bool fill = false;
    bool bad[4] = {false, false, false, false};
};

int N, M, B;
char a[50][50];
space b[50][50][7][12];
short best[50][50][60][(1<<10)-1];
int startx, starty;
int endx, endy;

int dx[] = {0, 0, 1, -1, 0};
int dy[] = {-1, 1, 0, 0, 0};

int opp[] = {1, 0, 3, 2, 4};

struct state {
    int r, c;
    short t;
    int co = 0;
};

bool good(state s, int d, short t) {
    if (s.r < 0 || s.r >= N || s.c < 0 || s.c >= M) {
        return false;
    }
    if (a[s.r][s.c] == '#') {
        return false;
    }
    if (d == 4) {
        for (short i = 1; i <= 6; i++) {
            if (b[s.r][s.c][i][t%(2*i)].fill) {
                return false;
            }
        }
        return true;
    } else {
        for (short i = 1; i <= 6; i++) {
            if (b[s.r][s.c][i][t%(2*i)].bad[d] || b[s.r][s.c][i][t%(2*i)].fill) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    // auto start = chrono::high_resolution_clock::now();
    cin >> N >> M >> B;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'S') {
                startx = i;
                starty = j;
                a[i][j] = '.';
            } else if (a[i][j] == 'E') {
                endx = i;
                endy = j;
                a[i][j] = '.';
            } else if (a[i][j] == 'C') {
                a[i][j] = '0' + cnt;
                cnt++;
            }
        }
    }
    for (int i = 0; i < B; i++) {
        int r, c;
        cin >> r >> c;
        string s;
        cin >> s;
        int d;
        int l = s.length();
        for (int j = 0; j < l; j++) {
            if (s[j] == 'U') {
                d = 0;
            } else if (s[j] == 'D') {
                d = 1;
            } else if (s[j] == 'R') {
                d = 2;
            } else if (s[j] == 'L') {
                d = 3;
            }
            b[r][c][l][j+1].bad[opp[d]] = true;
            r += dy[d];
            c += dx[d];
            b[r][c][l][j+1].fill = true;
        }
        for (int j = 0; j < l; j++) {
            if (s[l-1-j] == 'U') {
                d = opp[0];
            } else if (s[l-1-j] == 'D') {
                d = opp[1];
            } else if (s[l-1-j] == 'R') {
                d = opp[2];
            } else if (s[l-1-j] == 'L') {
                d = opp[3];
            }
            b[r][c][l][(j+l+1)%(2*l)].bad[opp[d]] = true;
            r += dy[d];
            c += dx[d];
            b[r][c][l][(j+l+1)%(2*l)].fill = true;
        }
    }
    queue<state> q;
    state s;
    s.r = startx;
    s.c = starty;
    s.t = 0;
    q.push(s);
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 60; k++) {
                for (int l = 0; l < (1<<10)-1; l++) {
                    best[i][j][k][l] = 32767;
                }
            }
        }
    }
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        if (cur.t >= best[cur.r][cur.c][cur.t%60][cur.co]) {
            continue;
        } else {
            best[cur.r][cur.c][cur.t%60][cur.co] = cur.t;
        }
        if (cur.r == endx && cur.c == endy && cur.co == (1<<cnt)-1) {
            cout << cur.t << endl;
            // auto stop = chrono::high_resolution_clock::now();
            // auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
            // cout << "Time: " << duration.count() << "ms" << endl;
            return 0;
        }
        for (int i = 0; i < 5; i++) {
            state next;
            next.r = cur.r+dy[i];
            next.c = cur.c+dx[i];
            next.t = cur.t+1;
            next.co = cur.co;
            if (good(next, i, next.t)) {
                if (a[next.r][next.c] != '.') {
                    next.co |= (1<<(a[next.r][next.c]-'0'));
                }
                q.push(next);
            }
        }
    }
    cout << "NOT POSSIBLE" << endl;
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
    // cout << duration.count() << endl;
}