#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s; cin >> s;
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        bool pm = false;
        if (h >= 12) {
            pm = true;
            if (h > 12) h -= 12;
        }
        if (h == 0) h = 12;
        cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << " " << (pm ? " PM" : " AM") << endl;
    }
    return 0;
}