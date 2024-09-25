#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        int N = s.size();
        int tot = 0;
        int two = -1;
        for (int i = 0; i < N; i++) {
            tot += s[i]-'0';
            if (s[i]=='2') {
                two = i;
            }
        }
        if (s[N-1]=='2') {
            cout << s << " " << 2 << "\n";
            continue;
        }
        if (tot%3==0) {
            cout << s << " " << 3 << "\n";
        } else if (tot%3==1) {
            cout << s.substr(0, N-1) << " " << 3 << "\n";
        } else {
            if (two==-1) {
                if (N%2==1) s = s.substr(0, N-1);
                cout << s << " " << 11 << "\n";
            } else {
                s = s.substr(0, two) + s.substr(two+1);
                cout << s << " " << 3 << "\n";
            }
        }
    }
    return 0;
}