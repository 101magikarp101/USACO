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
int a[200005];

int gcd(int a, int b) {
    if (b==0) return a;
    if (a==0) {
        return b;
    }
    return gcd(b%a, a);
}

bool solve(int x) {
    if (x==N) return true;
    int ans = abs(a[x]-a[0]);
    for (int i = 0; i < x; i++) {
        int g = abs(a[i+x]-a[i]);
        for (int j = 1; j < N/x; j++) {
            g = gcd(g, abs(a[j*x+i]-a[i+j*x-x]));
        }
        // cout << "g: " << g << " x: " << x << endl;
        ans = gcd(g, ans);
    }
    if (ans == 1) return false;
    else return true;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i*i <= N; i++) {
            if (N%i==0) {
                if (solve(i)) {
                    ans++;
                }
                if (i*i != N) {
                    if (solve(N/i)) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}