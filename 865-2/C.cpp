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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N;
ll a[300005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (N%2==1) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 0; i <= N-3; i++) {
            ll dif = a[i+1]-a[i];
            a[i+1] -= dif;
            a[i+2] -= dif;
        }
        if (a[N-2] <= a[N-1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}