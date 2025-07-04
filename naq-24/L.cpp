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
char a[11][11];
uset<ll> vis[11][11];
vt<pii> snek;
int ex, ey;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

ll stoh() {
    ll h = 0;
    for (int i = 1; i < sz(snek); i++) {
        int xd = snek[i-1].x-snek[i].x;
        int yd = snek[i-1].y-snek[i].y;
        h*=4;
        if (xd==1) h+=0;
        else if (xd==-1) h+=1;
        else if (yd==1) h+=2;
        else h+=3;
    }
    return h;
}

void forward() {
    // cout << snek[sz(snek)-1].x << " " << snek[sz(snek)-1].y << endl;
    a[snek.rbegin()->x][snek.rbegin()->y] = '.';
    for (int i = sz(snek)-1; i > 0; i--) {
        snek[i] = snek[i-1];
    }
}

bool dfs(int x, int y) {
    // cout << "a" << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    if (x==ex && y==ey) return 1;
    ll h = stoh();
    if (vis[x][y].count(h)) return 0;
    vis[x][y].insert(h);
    vt<pii> orig = vt<pii>(snek);
    pii tail = snek[sz(snek)-1];
    // cout << "orig" << endl;
    // for (int i = 0; i < sz(orig); i++) { 
    //     cout << orig[i].x << " " << orig[i].y << endl;
    // }
    forward();
    for (int d = 0; d < 4; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];
        if (!in(nx,ny)) continue;
        if (a[nx][ny]!='.' || (nx==tail.x&&ny==tail.y&&sz(snek)==2)) continue;
        snek[0] = {nx,ny};
        a[nx][ny] = 'X';
        bool res = dfs(nx, ny);
        if (res) return 1;
        a[nx][ny] = '.';
    }
    snek = orig;
    a[snek[sz(snek)-1].x][snek[sz(snek)-1].y] = 'X';
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int sx = 0, sy = 0;
    int ma = 0;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
            if (s[j] == '0') {
                sx = i;
                sy = j;
            }
            if (s[j] == 'A') {
                ex = i;
                ey = j;
                a[i][j] = '.';
            }
            if (s[j] >= '0' && s[j] <= '9') {
                ma = max(ma,s[j]-'0'+1);
            } else if (s[j] >= 'a' && s[j] <= 'f') {
                ma = max(ma,s[j]-'a'+11);
            }
        }
    }
    snek = vt<pii>(ma,{0,0});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] >= '0' && a[i][j] <= '9') {
                snek[a[i][j]-'0'] = {i,j};
                a[i][j] = 'X';
            } else if (a[i][j] >= 'a' && a[i][j] <= 'f') {
                snek[a[i][j]-'a'+10] = {i,j};
                a[i][j] = 'X';
            }
        }
    }
    // cout << "snek" << endl;
    // for (int i = 0; i < sz(snek); i++) {
    //     cout << snek[i].x << " " << snek[i].y << endl;
    // }
    bool ans = dfs(sx,sy);
    cout << ans << endl;
    return 0;
}