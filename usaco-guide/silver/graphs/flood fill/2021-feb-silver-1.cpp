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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N;
map<pii, bool> vis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 , -1};

int check(int i, int j);

bool comf(int i, int j) {
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if (vis.find({nx, ny}) != vis.end()) {
            cnt++;
        }
    }
    return cnt == 3;
}

int place(int i, int j) {
    int cnt = 1;
    cnt += check(i, j);
    for (int k = 0; k < 4; k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        cnt += check(nx, ny);
    }
    return cnt;
}

int check(int i, int j) {
    // cout << "i: " << i << " j: " << j << endl;
    // cout << "comf: " << comf(i, j) << endl;
    if (vis.find({i, j}) == vis.end()) return 0;
    if (comf(i, j)) {
        for (int k = 0; k < 4; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if (vis.find({nx, ny}) == vis.end()) {
                vis[{nx, ny}] = true;
                return place(nx, ny);
            }
        }
    } else {
        return 0;
    }
}

int main() {
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (vis.find({a, b}) == vis.end()) {
            vis[{a, b}] = true;
            ans += check(a, b);
            for (int k = 0; k < 4; k++) {
                int nx = a+dx[k];
                int ny = b+dy[k];
                ans += check(nx, ny);
            }
        } else {
            ans--;
        }
        // cout << "vis: " << endl;
        // for (auto i : vis) {
        //     cout << i.first.first << " " << i.first.second << endl;
        // }
        cout << ans << endl;
    }
}