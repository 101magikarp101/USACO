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
set<ll> s;
ll a[200003];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        s.clear();
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            a[i] = x;
        }
        bool good = false;
        for (int i = 0; i < N; i++) {
            sum += a[i]*((i%2==0)?1:-1);
            if (s.find(sum) != s.end() || sum == 0) {
                good = true;
                break;
            }
            s.insert(sum);
        }
        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}