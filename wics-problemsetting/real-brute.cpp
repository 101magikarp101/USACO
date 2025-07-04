#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

struct piece {
    vt<pii> p;
};

piece pieces[8] = {
    //X
    //X
    //XX
    {
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}}
    },
    //XXX
    //X
    {
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}}
    },
    //XX
    // X
    // X
    {
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}}
    },
    //  X
    //XXX
    {
        {{0, 0}, {1, 0}, {1, -1}, {1, -2}}
    },
    // X
    // X
    //XX
    {
        {{0, 0}, {1, 0}, {2, 0}, {2, -1}}
    },
    //X
    //XXX
    {
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}}
    },
    //XX
    //X
    //X
    {
        {{0, 0}, {0, 1}, {1, 0}, {2, 0}}
    },
    //XXX
    //  X
    {
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}}
    }
};

bool in(vt<vt<int>> &grid, int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool good(vt<vt<int>> &grid, int x, int y, int n, int m, piece p) {
    for(auto i : p.p) {
        if(!in(grid, x+i.x, y+i.y, n, m) || grid[x+i.x][y+i.y] != -1) {
            return false;
        }
    }
    return true;
}

void place(vt<vt<int>> &grid, int x, int y, piece p, int cnt) {
    for(auto i : p.p) {
        grid[x+i.x][y+i.y] = cnt;
    }
}

bool complete(vt<vt<int>> &grid) {
    for(auto i : grid) {
        for(auto j : i) {
            if(j == -1) {
                return false;
            }
        }
    }
    return true;
}

int dfs(vt<vt<int>> &grid, int cnt, int n, int m) {
    if(cnt == n*m) {
        return complete(grid);
    }
    int x = cnt/m, y = cnt%m;
    if (grid[x][y] != -1) {
        return dfs(grid, cnt+1, n, m);
    }
    int res = 0;
    for(int i = 0; i < 8; i++) {
        piece p = pieces[i];
        if(good(grid, x, y, n, m, p)) {
            place(grid, x, y, p, cnt);
            res += dfs(grid, cnt+1, n, m);
            place(grid, x, y, p, -1);
        }
    }
    return res;
}

int solve(int n, int m) {
    vt<vt<int>> grid(n, vt<int>(m, -1));
    int ans = dfs(grid, 0, n, m);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    int ans = solve(14, 4);
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}