#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string erm, what; cin >> erm >> what;
    int lore; cin >> lore;
    int skull = 510;
    for (int roll = 1; roll <= lore; roll++) {
        string ur; cin >> ur;
        int the = ur[ur.size()-1]-'0';
        int wha = ur[0]-'0';
        the = the+wha+1;
        if (the > what.size()) {
            cout << skull*what.size() << '\n';
            skull = skull+the;
        } else {
            if (what[the-1]-'0' > erm.size()) {
                cout << erm.size()*what.size() << '\n';
            } else {
                if (what[the-1]-'0' < 1) {
                    cout << "erm what the sigma" << '\n';
                } else {
                    if (5 > erm[what[the-1]-'0'-1]-'0') {
                        cout << erm[what[the-1]-'0'-1]-'0' << '\n';
                    } else {
                        cout << 3*(erm[what[the-1]-'0'-1]-'0') << '\n';
                    }
                }
            }
        }
    }
    return 0;
}