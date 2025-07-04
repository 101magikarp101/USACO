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

int T, N, M;
char a[21][21];
string v = "vika";

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < M; j++) {
                a[i][j] = s[j];
            }
        }
        int cnt = 0;
        for (int j = 0; j < M; j++) {
            for (int i = 0; i < N; i++) {
                if (cnt == 4) break;
                if (v[cnt] == a[i][j]) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt == 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}