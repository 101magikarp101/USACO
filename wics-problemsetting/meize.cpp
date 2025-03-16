#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MX = 1e18;

ll a[1005];
ll b[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int q;
    cin >> q;

    // Min cutoff to barely make it past ith blow
    vector<ll> cutoffs(n);
    __int128 newz;
    for (int i = 0; i < n; i++) {
        ll z = 1;
        for (int j = i; j >= 0; j--) {
            newz = ((__int128) z * b[j] + a[j] - 1) / a[j];
            if (newz > MX) {
                z = MX + 1;
                break;
            }
            z = newz;
        }
        cutoffs[i] = z;
    }

    while (q--) {
        ll m;
        cin >> m;
        if (m == 0) {
            cout << 0 << '\n';
        } else {
            int i = upper_bound(cutoffs.begin(), cutoffs.end(), m) - cutoffs.begin();
            if (i == n) {
                cout << -1 << '\n';
            } else {
                cout << i + 1 << '\n';
            }
        }
    }
    return 0;
}
