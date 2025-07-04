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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vt<vt<char>> grid(7, vt<char>(7));

int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};

bool good(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

bool check(vt<vt<bool>> a) {
    set<int> s1, s2, s3;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j]) {
                s1.insert(i);
                s2.insert(j);
                s3.insert(grid[i][j]-'a');
                for (int k = 0; k < 8; k++) {
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if (good(ni,nj)) {
                        if (a[ni][nj]) {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if (s1.size() != N || s2.size() != N || s3.size() != N) {
        return 0;
    }
    return 1;
}

pair<bool,vt<vt<bool>>> gen(int i, vt<vt<bool>> a) {
    pair<bool,vt<vt<bool>>> res = {0,a};
    for (int j = 0; j < N; j++) {
        vt<vt<bool>> b = a;
        b[i][j] = 1;
        if (i==N-1) {
            if (check(b)) {
                return {1,b};
            }
        } else {
            auto c = gen(i+1,b);
            if (c.first) {
                return c;
            }
        }
    }
    return res;
}

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j];
        }
    }
    auto ans = gen(0,vt<vt<bool>>(N,vt<bool>(N,0)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c = grid[i][j];
            if (ans.second[i][j]) {
                c = toupper(c);
            }
            cout << c;
        }
        cout << endl;
    }
}