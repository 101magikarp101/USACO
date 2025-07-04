#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int C, N;
    cin >> C >> N;
    int chickens[20000];
    pair<int, int> cows[20000];
    bool visited[20000];
    for (int i = 0; i < C; i++) {
        cin >> chickens[i];
    }
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cows[i] = {a, b};
    }
    sort(chickens, chickens + C);
    sort(cows, cows + N, [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    int ans = 0;
    for (int i = 0; i < C; i++) {
        pair<int, int> earliest = {-1, INT32_MAX};
        int index = -1;
        for (int j = 0; j < N; j++) {
            if (cows[j].first > chickens[i]) {
                break;
            }
            if (!visited[j] && cows[j].first <= chickens[i] && cows[j].second >= chickens[i]) {
                if (cows[j].second < earliest.second) {
                    earliest = cows[j];
                    index = j;
                }
            }
        }
        if (earliest.first != -1) {
            ans++;
            visited[index] = true;
        }
    }
    cout << ans << endl;
}