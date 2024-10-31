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

#define ll long long

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, K, R;
bool visited[101][101] = {false};
int walls[201][201] = {0};
struct cow {
    int r, c;
    cow(int r, int c) {
        this->r = r;
        this->c = c;
    }
    bool operator<(const cow& other) const {
        if (r == other.r) {
            return c < other.c;
        }
        return r < other.r;
    }
    bool operator==(const cow& other) const {
        return r == other.r && c == other.c;
    }
    bool operator > (const cow& other) const {
        if (r == other.r) {
            return c > other.c;
        }
        return r > other.r;
    }
};
set<cow> cows;

bool isValid(int i, int j) {
    return i >= 1 && i <= N && j >= 1 && j <= N;
}

int floodfill(int r, int c) {
    visited[r][c] = true;
    int ans = 0;
    if (binary_search(cows.begin(), cows.end(), cow(r, c))) {
        ans++;
    }
    for (int k = 0; k < 4; k++) {
        int x = r + dx[k];
        int y = c + dy[k];
        if (isValid(x, y) && !visited[x][y] && walls[r+x-1][c+y-1] == 0) {
            ans += floodfill(x, y);
        }
    }
    return ans;
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> N >> K >> R;
    for (int i = 0; i < R; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        walls[a+c-1][b+d-1] = 1;
    }
    // cout << "walls: " << endl;
    // for (int i = 1; i <= 2*N-1; i++) {
    //     for (int j = 1; j <= 2*N-1; j++) {
    //         cout << walls[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        cows.insert(cow(a, b));
    }
    int ans = 0;
    vector<int> nums;
    for (auto it = cows.begin(); it != cows.end(); it++) {
        cow c = *it;
        if (visited[c.r][c.c]) continue;
        nums.push_back(floodfill(c.r, c.c));
    }
    // cout << "nums: ";
    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < nums.size(); i++) {
        ans += nums[i] * (K - nums[i]);
    }
    cout << ans / 2 << endl;
}