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

int T, N;
ll arr[100005];
map<ll, ll> m;
vector<ll> fac[100005];
ll hmm[100005];

int main() {
    for (ll i = 1; i <= 100000; i++) {
        for (ll j = 1; j*j <= i; j++) {
            if (i%j == 0) {
                fac[i].push_back(j);
                if (j*j != i) {
                    fac[i].push_back(i/j);
                }
            }
        }
        sort(fac[i].begin(), fac[i].end());
    }
    for (ll i = 1; i <= 100000; i++) {
        for (int j = 0; j < fac[i].size()-1; j++) {
            hmm[i] += hmm[fac[i][j]];
        }
        hmm[i] = i-hmm[i];
    }
    // cout << "hmm: ";
    // for (int i = 1; i <= 10; i++) {
    //     cout << hmm[i] << " ";
    // }
    // cout << endl;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+N);
        m.clear();
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            for (ll j = 0; j < fac[arr[i]].size(); j++) {
                ans += hmm[fac[arr[i]][j]]*m[fac[arr[i]][j]]*(N-i-1);
                // cout << "arr[i]: " << arr[i] << " fac[arr[i]][j]: " << fac[arr[i]][j] << endl;
                // cout << "hmm: " << hmm[fac[arr[i]][j]] << " m: " << m[fac[arr[i]][j]] << " N-i-1: " << N-i-1 << endl;
                // cout << "ans: " << ans << endl;
            }
            for (ll j = 0; j < fac[arr[i]].size(); j++) {
                m[fac[arr[i]][j]]++;
            }
        }
        cout << ans << endl;
    }
}