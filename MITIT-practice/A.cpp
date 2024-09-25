#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        N = s.size();
        bool good = false;
        for (int i = 0; i < N-2; i++) {
            if ((N-i-1)%2==0) {
                string a = s.substr(i+1, (N-i-1)/2);
                string b = s.substr(i+1+(N-i-1)/2, (N-i-1)/2);
                if (a == b) {
                    good = true;
                    break;
                }
            }
        }
        cout << (good ? "YES" : "NO") << "\n";
    }
    return 0;
}