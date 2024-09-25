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

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                cout << 2*N-i << " ";
            } else {
                cout << i+1 << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < N; i++) {
            if (i % 2==0) {
                cout << i+1 << " ";
            } else {
                cout << i+N << " ";
            }
        }
        cout << endl;
    }
}