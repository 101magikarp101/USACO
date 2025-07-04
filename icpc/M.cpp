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
#define pll pair<ll, ll>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

int N;
vector<int> a;

int conv(int x) {
    if (x < 0) return a.size() - 1;
    if (x >= a.size()) return 0;
    return x;
}

int main() {
    ll ans = 0;
    cin >> N;
    a = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    
    for (int i = 0; i < a.size(); i++) {
        for (int k = -1; k <= 1; k += 2) {
            while (a[i] > 1 && a.size() > 1) {
                ll res = min(a[i] / 2, a[conv(i+k)]);
                int j = conv(i+k);
                if (a[j] == 1) break;
                cout << "k: " << k << " res: " << res << endl;
                cout << "a: ";
                for (int j = 0; j < a.size(); j++) {
                    cout << a[j] << " ";
                }
                cout << endl;
                cout << "i: " << i << " res: " << res << " j: " << j << endl;
                a[i] -= res * 2;
                a[j] -= res;
                ans += res;
                if (a[i] == 0) {
                    a.erase(a.begin() + i);
                    i--;
                }
                if (a[j] == 0) {
                    a.erase(a.begin() + j);
                    if (i > 0) i--;
                }
            }
        }
    }
    ans += a.size() / 3;
    cout << ans << endl;
}