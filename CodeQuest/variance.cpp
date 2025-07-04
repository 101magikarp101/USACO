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

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        vt<double> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        double avg = 0;
        for (int i = 0; i < N; i++) {
            avg += b[i]-a[i];
        }
        avg/=N;
        ll hm = llround(avg*10000000);
        string ans = to_string(hm);
        cout << hm << " ";
        cout << fixed << setprecision(15) << avg << " ";
        cout << fixed << setprecision(2) << avg << endl;
        cout << ans.substr(0, ans.size()-7) << "." << (ans.substr(ans.size()-7, 2)-'0'+((ans[ans.size()-5]-'5')>=0?1:0)) << endl;
    }
}