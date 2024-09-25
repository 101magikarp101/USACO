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

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c; cin >> n >> m >> c;
    if (c == 2) {
        if (n>2 && n<=4 && m <= 6) {
            vt<vt<int>> ans = {{1,1,1,2,2,2},{1,2,2,1,1,2},{2,1,2,1,2,1},{2,2,1,2,1,1}};
            /*
            1 1 1 2 2 2 
1 2 2 1 1 2 
2 1 2 1 2 1 
2 2 1 2 1 1 
            */
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        } else if (n <= 2) {
            vt<vt<int>> ans = {{1,1,1,1,1,1,1,1,1,1},{2,2,2,2,2,2,2,2,2,2}};
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        } else if (m>2 && m <= 4) {
            vt<vt<int>> ans = {{1,1,2,2},{1,2,1,2},{1,2,2,1},{2,1,1,2},{2,1,2,1},{2,2,1,1}};
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[j][i] << " ";
                }
                cout << endl;
            }
        } else if (m <= 2) {
            vt<vt<int>> ans = {{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}};
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    } else {
        if (n <= 9 && m <= 9) {
            /*
            2 1 1 1 2 3 3 3 3 
1 3 3 1 1 2 3 2 2 
3 1 3 2 2 1 1 2 3 
3 2 2 1 3 1 2 2 1 
3 3 2 1 2 3 1 1 2 
2 1 3 2 1 2 2 3 1 
3 2 1 2 1 1 3 1 2 
3 2 1 3 2 2 1 3 1 
1 1 3 3 3 3 2 1 2 
            */
           vt<vt<int>> ans = {{2,1,1,1,2,3,3,3,3},{1,3,3,1,1,2,3,2,2},{3,1,3,2,2,1,1,2,3},{3,2,2,1,3,1,2,2,1},{3,3,2,1,2,3,1,1,2},{2,1,3,2,1,2,2,3,1},{3,2,1,2,1,1,3,1,2},{3,2,1,3,2,2,1,3,1},{1,1,3,3,3,3,2,1,2}};
           for (int i = 0; i < n; i++) {
               for (int j = 0; j < m; j++) {
                   cout << ans[i][j] << " ";
               }
               cout << endl;
           }
        } else if (n<=8 && m == 10) {
            /*
            1212233311
3122131213
1221312332
3312311122
3111223232
1332122133
2123323123
3133212321
            */
            vt<vt<int>> ans = {{1,2,1,2,2,3,3,3,1,1},{3,1,2,2,1,3,1,2,1,3},{1,2,2,1,3,1,2,3,3,2},{3,3,1,2,3,1,1,2,2,1},{3,1,1,1,2,2,3,2,3,2},{1,3,3,2,1,2,1,3,3,3},{2,1,2,3,3,2,3,1,2,3},{3,1,3,3,2,1,2,3,2,1}};
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        } else if (n==10 && m<=8) {
            /*
            1 2 1 2 2 3 3 3 1 1
            3 1 2 2 1 3 1 2 1 3
            1 2 2 1 3 1 2 3 3 2
            3 3 1 2 3 1 1 1 2 2
            3 1 1 1 2 2 3 2 3 2
            1 3 3 2 1 2 2 1 3 3
            2 1 2 3 3 2 3 1 2 3
            3 1 3 3 2 1 2 3 2 1
            */
            vt<vt<int>> ans = {{1,3,1,3,3,1,2,3},{2,1,2,3,1,3,1,1},{1,2,2,1,1,3,2,3},{2,2,1,2,1,2,3,3},{2,1,3,3,2,1,3,2},{3,3,1,1,2,3,2,1},{3,1,2,1,3,2,3,2},{3,2,3,1,2,1,1,3},{1,1,3,2,3,3,2,2},{1,3,2,2,2,3,3,1}};
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[j][i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}