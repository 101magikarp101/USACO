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
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int N, Q;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    cin >> Q;
    while (Q--) {
        int l, r; cin >> l >> r;
        ll x; cin >> x;
        ll b = x, e = 0;
        for (int i = l; i <= r; i++) {
            if (b<=e) {
                b+=a[i];
            } else {
                e+=a[i];
            }
        }
        cout << b-e << endl;
    }
    return 0;
}