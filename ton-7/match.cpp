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

int T, N, X;
pair<int, int> a[200005];
pair<int, int> b[200005];
int ans[200005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> X;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            a[i] = {x, i};
        }
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            b[i] = {x, i};
        }
        sort(a, a + N);
        sort(b, b + N);
        int it = 0;
        bool good = true;
        memset(ans, 0, sizeof(ans));
        for (int i = N-X; i < N; i++) {
            if (a[i].first > b[it].first) {
                ans[a[i].second] = b[it].first;
                it++;
            } else {
                good = false;
                break;
            }
        }
        if (!good) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < N-X; i++) {
            if (a[i].first <= b[it].first) {
                ans[a[i].second] = b[it].first;
                it++;
            } else {
                good = false;
                break;
            }
        }
        if (!good) {
            cout << "NO" << endl;
            continue;
        }
        // cout << "a: ";
        // for (int i = 0; i < N; i++) {
        //     cout << a[i].first << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < N; i++) {
        //     cout << a[i].second << " ";
        // }
        // cout << endl;
        // cout << "ans: ";
        // for (int i = 0; i < N; i++) {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}