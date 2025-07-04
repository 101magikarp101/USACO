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
 
int N;
int vis[1000003];
 
int main () {
    //start timer
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ll up = (ll)sqrt(a);
        for (ll j = 1; j <= up; j++) {
            if (a%j == 0) {
                vis[j]++;
                if (j != a/j) {
                    vis[a/j]++;
                }
            }
        }
    }
    for (int i = 1000000; i >= 1; i--) {
        if (vis[i] >= 2) {
            cout << i << endl;
            break;
        }
    }
    //end timer
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout << duration.count() << endl;
}
