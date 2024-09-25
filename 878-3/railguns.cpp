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

using namespace std;

int T;
int N, M, R;

bool isValid(int x, int y) {
    return x >= 0 && x <= N && y >= 0 && y <= M;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cin >> R;
        vector<vector<vector<bool>>> v = vector<vector<vector<bool>>>(N + 1, vector<vector<bool>>(M + 1, vector<bool>(N + M + R + 1, false)));
        vector<vector<vector<bool>>> free = vector<vector<vector<bool>>>(N + 1, vector<vector<bool>>(M + 1, vector<bool>(N + M + R + 1, true)));
        map<int, set<pair<int, int>>> m;
        for (int j = 0; j < R; j++) {
            int t, d, c;
            cin >> t >> d >> c;
            m[t].insert(make_pair(d, c));
        }
        for (int t = 1; t <= N + M + R; t++) {
            for (auto it = m[t].begin(); it != m[t].end(); it++) {
                int d = it->first;
                int c = it->second;
                if (d == 1) {
                    for (int i = 0; i <= M; i++) {
                        free[c][i][t] = false;
                    }
                }
                else {
                    for (int i = 0; i <= N; i++) {
                        free[i][c][t] = false;
                    }
                }
            }
        }
        v[0][0][0] = true;
        int ans = 0;
        bool flag = false;
        for (int t = 1; t <= N + M + R; t++) {
            for (int i = N; i >= 0; i--) {
                for (int j = M; j >= 0; j--) {
                    if (free[i][j][t] && (v[i][j][t - 1] || (isValid(i - 1, j) && v[i - 1][j][t - 1]) || (isValid(i, j - 1) && v[i][j - 1][t - 1]))) {
                        v[i][j][t] = true;
                    }
                }
            }
            // cout << "v[" << t << "]:" << endl;
            // for (int i = 0; i <= N; i++) {
            //     for (int j = 0; j <= M; j++) {
            //         cout << v[i][j][t] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "free[" << t << "]:" << endl;
            // for (int i = 0; i <= N; i++) {
            //     for (int j = 0; j <= M; j++) {
            //         cout << free[i][j][t] << " ";
            //     }
            //     cout << endl;
            // }
            if (v[N][M][t]) {
                flag = true;
                ans = t;
                break;
            }
        }
        if (flag) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}