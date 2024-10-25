#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

int N, M;
char a[55][55];
int spike[1005];
bool safe[55][55][5];
bool vis[55][55][1005];

int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 5; k++) {
                if (a[i][j] != '#') safe[i][j][k] = 1;
                else safe[i][j][k] = 0;
            }
        }
    }
}

void calcnorth() {
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (a[i][j] == '#') break;
            safe[i][j][1] = 0;
        }
    }
}

void calceast() {
    for (int i = 0; i < N; i++) {
        for (int j = M-1; j >= 0; j--) {
            if (a[i][j] == '#') break;
            safe[i][j][2] = 0;
        }
    }
}

void calcsouth() {
    for (int j = 0; j < M; j++) {
        for (int i = N-1; i >= 0; i--) {
            if (a[i][j] == '#') break;
            safe[i][j][3] = 0;
        }
    }
}

void calcwest() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '#') break;
            safe[i][j][4] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int sx, sy; cin >> sx >> sy;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
        }
    }
    string s; cin >> s;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'N') spike[i] = 1;
        if (s[i] == 'E') spike[i] = 2;
        if (s[i] == 'S') spike[i] = 3;
        if (s[i] == 'W') spike[i] = 4;
    }
    reset();
    calcnorth();
    calceast();
    calcsouth();
    calcwest();
    vis[sx][sy][0] = 1;
    for (int k = 1; k <= sz(s); k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int d = 0; d < 5; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (in(ni,nj)) {
                        if (safe[ni][nj][spike[k-1]] && vis[i][j][k-1]) {
                            vis[ni][nj][k] = 1;
                        }
                    }
                }
            }
        }
    }
    bool ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j][sz(s)]) {
                ans = 1;
            }
        }
    }
    cout << (ans?"Go Comets!":"Ouch!!!") << endl;
    return 0;
}