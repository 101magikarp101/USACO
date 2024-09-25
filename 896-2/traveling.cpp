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
#define pll pair<ll, ll>

using namespace std;

int T, N, K, A, B;
pll a[200001];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K >> A >> B;
        for (int i = 1; i <= N; i++) {
            ll x, y;
            cin >> x >> y;
            a[i] = {x, y};
        }
        if (A <= K && B <= K) {
            cout << 0 << endl;
            continue;
        }
        ll dist = abs(a[A].first-a[B].first) + abs(a[A].second-a[B].second);
        if (K==0) {
            cout << dist << endl;
            continue;
        }
        ll dista = 1e18;
        ll distb = 1e18;
        if (A > K) {
            for (int i = 1; i <= K; i++) {
                ll d = abs(a[i].first-a[A].first) + abs(a[i].second-a[A].second);
                if (d < dista) {
                    dista = d;
                }
            }
        } else {
            dista = 0;
        }
        if (dista > dist) {
            cout << dist << endl;
            continue;
        }
        if (B > K) {
            for (int i = 1; i <= K; i++) {
                ll d = abs(a[i].first-a[B].first) + abs(a[i].second-a[B].second);
                if (d < distb) {
                    distb = d;
                }
            }
        } else {
            distb = 0;
        }
        cout << min(dist, dista+distb) << endl;
    }
}