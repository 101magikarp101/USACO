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

int T, N, K;
ll c[200001];
ll ans[200001];
vector<int> ing[200001];

void calculate(int s) {
    ll res = 0;
    for (int i = 0; i < ing[s].size(); i++) {
        if (ans[ing[s][i]] == -1) {
            calculate(ing[s][i]);
        }
        res += ans[ing[s][i]];
        if (res >= c[s]) {
            break;
        }
    }
    ans[s] = min(res, c[s]);
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        memset(ans, -1, sizeof(ans));
        memset(c, 0, sizeof(c));
        memset(ing, 0, sizeof(ing));
        for (int i = 1; i <= N; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < K; i++) {
            int temp;
            cin >> temp;
            ans[temp] = 0;
        }
        for (int i = 1; i <= N; i++) {
            int m;
            cin >> m;
            if (m == 0) {
                if (ans[i] == -1) {
                    ans[i] = c[i];
                }
                continue;
            }
            for (int j = 0; j < m; j++) {
                int temp;
                cin >> temp;
                ing[i].push_back(temp);
            }
        }
        for (int i = 1; i <= N; i++) {
            if (ans[i] == -1) {
                calculate(i);
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}