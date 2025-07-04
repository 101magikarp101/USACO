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

int T, A, B, N;
int a[101];

int main() {
    cin >> T;
    while (T--) {
        cin >> A >> B >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        ll ans = B;
        for (int i = 0; i < N; i++) {
            if (a[i] >= A) {
                ans += A-1;
            } else {
                ans += a[i];
            }
        }
        cout << ans << endl;
    }
}