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

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int ans = -1;
        int best = -1;
        for (int j = 1; j <= N; j++) {
            int a, b;
            cin >> a >> b;
            if (a <= 10 && b > best) {
                ans = j;
                best = b;
            }
        }
        cout << ans << endl;
    }
}
