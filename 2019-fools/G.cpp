#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string ord = "RPS";
    string res = "";
    string play = "RPSRPSRPSR";
    for (int i = 0; i < 10; i++) {
        cout << play[i] << endl;
        cout.flush();
        string s; cin >> s;
        res += s;
    }
    if (res == "RRRRRRRRRR") {
        for (int i = 0; i < 10; i++) {
            cout << "P" << endl;
            cout.flush();
        }
    } else if (res == "PPPPPPPPPP") {
        for (int i = 0; i < 10; i++) {
            cout << "S" << endl;
            cout.flush();
        }
    } else if (res == "SSSSSSSSSS") {
        for (int i = 0; i < 10; i++) {
            cout << "R" << endl;
            cout.flush();
        }
    } else if (res.substr(1,res.size()) == "RPSRPSRPS") {
        for (int i = 0; i < 10; i++) {
            cout << ord[(i+1)%3] << endl;
            cout.flush();
        }
    } else if (res.substr(1,res.size()) == "PSRPSRPSR") {
        for (int i = 11; i > 1; i--) {
            cout << ord[i%3] << endl;
            cout.flush();
        }
    } else if (res.substr(1,res.size()) == "SRPSRPSRP") {
        for (int i = 0; i < 10; i++) {
            cout << "R" << endl;
            cout.flush();
        }
    }
    return 0;
}