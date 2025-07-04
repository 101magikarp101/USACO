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
#include <chrono>

#define ll long long

using namespace std;

ll T, N;
ll a[300005], b[300005];

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        sort(a, a+N);
        sort(b, b+N);
        ll suma = 0;
        ll sumb = 0;
        for (int i = 0; i < N; i++) {
            suma += a[i];
            sumb += b[i];
        }
        ll ans = min(suma+b[0]*N, sumb+a[0]*N);
        cout << ans << endl;
    }
    return 0;
}