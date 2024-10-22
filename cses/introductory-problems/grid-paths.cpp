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

string tar;
vt<char> s;
bool b[7][7];
int ans = 0;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
string dir = "RDLU";

bool match() {
    // for (char c : s) {
    //     cout << c;
    // }
    // cout << endl;
    for (int i = 0; i < sz(s); i++) {
        if (tar[i] != '?' && tar[i] != s[i]) return 0;
    }
    return 1;
}

bool good(int x, int y) {
    return x>=0&&x<7&&y>=0&&y<7&&!b[x][y];
}

void solve(int x, int y, int dis, int d) {
    if (x==6 && y==0 && dis!=49) return;
    if (dis==49 && x==6 && y==0) {
        ans += match();
        return;
    }
    for (int i = -1; i <= 1; i++) {
        int nd = (d+i+4)%4;
        int nd1 = (nd+3)%4, nd2 = (nd+1)%4;
        int nx = x+dx[nd], ny = y+dy[nd];
        int nnx = nx+dx[nd], nny = ny+dy[nd];
        int nx1 = nx+dx[nd1], ny1 = ny+dy[nd1];
        int nx2 = nx+dx[nd2], ny2 = ny+dy[nd2];
        // cout << nx << " " << ny << endl;
        if (good(nx,ny) && !(!good(nnx,nny)&&good(nx1,ny1)&&good(nx2,ny2))) {
            s.pb(dir[nd]);
            b[nx][ny]=1;
            solve(nx,ny,dis+1,nd);
            s.pop_back();
            b[nx][ny]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = std::chrono::high_resolution_clock::now();
    cin >> tar;
    b[0][0]=1;
    solve(0,0,1,0);
    cout << ans << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> time = end-start;
    // cerr << time.count() << endl;
    return 0;
}