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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N;
int d1, d2, d3;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> d1 >> d2 >> d3;
        if (d1+d2==d3) {
            if (d3+1 <= N) {
                cout << "YES" << endl;
                for (int i = 1; i <= N-1; i++) {
                    cout << i << " " << i+1 << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        } else if (d1+d3==d2) {
            if (d2+1 <= N) {
                cout << "YES" << endl;
                cout << 1 << " " << 3 << endl;
                cout << 2 << " " << 3 << endl;
                for (int i = 4; i <= N; i++) {
                    cout << 2 << " " << i << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        } else if (d2+d3==d1) {
            if (d1+1 <= N) {
                cout << "YES" << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 3 << endl;
                for (int i = 4; i <= N; i++) {
                    cout << 1 << " " << i << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        } else if ((d1+d3-d2)%2==0) {
            int x = (d1+d3-d2)/2;
            cout << x << endl;
            if (x<0) {
                cout << "NO" << endl;
                continue;
            }
            if (d1+d3-x+1 <= N) {
                cout << "YES" << endl;
                cout << 1 << " " << 4 << endl;
                cout << 3+d1-1 << " " << 2 << endl;
                for (int i = 4; i <= 3+d1-2; i++) {
                    cout << i << " " << i+1 << endl;
                }
                cout << 3+d1-1+d3-x-1 << " " << 3 << endl;
                for (int i = 3+x; i <= 3+d1-1+d3-x-2; i++) {
                    cout << i << " " << i+1 << endl;
                }
                for (int i = 3+d1-1+d3-x; i <= N; i++) {
                    cout << 3 << " " << i << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "WIP" << endl;
        }
    }
}