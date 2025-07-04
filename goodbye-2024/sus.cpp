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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)

class Solution {
public:
    bool check(vt<vt<char>> &a, int i, int j, char k) {
        int x = i/3*3, y = j/3*3;
        for (int n = 0; n < 9; n++) {
            if (a[i][n] == k || a[n][j] == k || a[x+n/3][y+n%3] == k) return 0;
        }
        return 1;
    }
    bool dfs(vt<vt<char>> &a, int t) {
        if (t == 81) return 1;
        const int i = t/9;
        const int j = t%9;
        if (a[i][j] != '.') return dfs(a, t+1);
        for (int k = '1'; k <= '9'; k++) {
            if (check(a, i, j, k)) {
                a[i][j] = k;
                if (dfs(a, t+1)) return 1;
                a[i][j] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0);
    }
};