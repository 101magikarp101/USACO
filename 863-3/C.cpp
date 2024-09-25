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
ll a[200005];
ll b[200005];

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        ll a[N];
        for (int i = 0; i < N-1; i++) {
            cin >> a[i];
            b[i] = -1;
        }
        b[N-1] = -1;
        b[0] = a[0];
        for (int i = 1; i < N-1; i++) {
            if (a[i] <= a[i-1]) {
                if (b[i] == -1 || b[i] == a[i]) {
                    b[i] = a[i];
                } else {
                    b[i+1] = a[i];
                }
            } else {
                if (b[i] == -1) {
                    b[i] = 0;
                    b[i+1] = a[i];
                } else {
                    b[i+1] = a[i];
                }
            }
        }
        if (b[N-1] == -1) {
            b[N-1] = 0;
        }
        for (int i = 0; i < N; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}