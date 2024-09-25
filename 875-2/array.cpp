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

int T, N;
int a[200001], b[200001];
map<int, int> m;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int count = 1;
        int ans = 0;
        for (int j = 0; j < N; j++) {
            cin >> a[j];
            if (j >= 1 && a[j] == a[j-1]) {
                count++;
            } else {
                count = 1;
            }
            m[a[j]] = max(m[a[j]], count);
            ans = max(ans, count);
        }
        count = 1;
        for (int j = 0; j < N; j++) {
            cin >> b[j];
            if (j >= 1 && b[j] == b[j-1]) {
                count++;
            } else {
                count = 1;
            }
            ans = max(ans, m[b[j]] + count);
        }
        cout << ans << endl;
        m.clear();
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    return 0;
}