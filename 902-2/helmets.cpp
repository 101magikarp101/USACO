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

int T, N, P;
int a[100002];
pair<ll, ll> b[100002];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> P;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            b[i] = make_pair(x, a[i]);
        }
        sort (b, b+N);
        ll sum = P;
        ll l = 0;
        ll r = N;
        while (l < r-1) {
            if (b[l].first < P) {
                sum += b[l].first * min(r-l-1,b[l].second);
                r -= (b[l].second-1);
                l++;
            } else {
                sum += P;
                l++;
            }
        }
        cout << sum << endl;
    }
}