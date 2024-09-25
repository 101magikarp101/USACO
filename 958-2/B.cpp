#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        string s; cin >> s;
        if (s.size() == 1) {
            cout << (s=="1"? "YES" : "NO") << endl;
            continue;
        }
        int l = -1, r = s.size()-1;
        bool a = 0, b = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i]=='1') {
                if (l==-1) l = i;
                if (i<s.size()-1 && s[i+1]=='1') {
                    cnt++;
                }
            }
        }
        a = (l<s.size()-1?s[l+1]=='1':0);
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i]=='1') {
                r = i;
                if (i>0 && s[i-1]=='1') {
                    b = 1;
                }
                break;
            }
        }
        // cout << l << " " << r << " " << cnt << endl;
        if (l == 0 && r == s.size()-1) {
            cout << "YES" << endl;
            continue;
        }
        if (l == 0 && cnt>0) {
            cout << "YES" << endl;
            continue;
        }
        if (r == s.size()-1 && cnt>0) {
            cout << "YES" << endl;
            continue;
        }
        if (l!=0 && r!=s.size()-1 && cnt>1) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}