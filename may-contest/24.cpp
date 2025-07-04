#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T;
vt<string> a;
int K;
string sym[] = {"+", "-", "*", "/"};

double solve(vt<string> &v) {
    vt<double> s;
    for (int i = 0; i < 7; i++) {
        if (v[i]=="+"||v[i]=="-"||v[i]=="*"||v[i]=="/") {
            if (s.size()<2) return -1;
            double x = s.back(); s.pop_back();
            double y = s.back(); s.pop_back();
            if (v[i]=="+") {
                s.push_back(x+y);
            } else if (v[i]=="-") {
                s.push_back(y-x);
            } else if (v[i]=="*") {
                s.push_back(x*y);
            } else {
                s.push_back(y/x);
            }
        } else {
            s.push_back(stod(v[i]));
        }
    }
    if (s.size()!=1) return -1;
    return s[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        a.clear();
        for (int i = 0; i < 4; i++) {
            string x; cin >> x;
            a.push_back(x);
        }
        cin >> K;
        bool ans = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    vt<string> v;
                    for (int l = 0; l < 4; l++) {
                        v.push_back(a[l]);
                    }
                    v.push_back(sym[i]);
                    v.push_back(sym[j]);
                    v.push_back(sym[k]);
                    vt<int> ord = {0,1,2,3,4,5,6};
                    do {
                        vt<string> v2;
                        for (int l = 0; l < 7; l++) {
                            v2.push_back(v[ord[l]]);
                        }
                        if (abs(solve(v2)-K)<1e-6) {
                            // for (int l = 0; l < 7; l++) {
                            //     cout << v2[l] << " ";
                            // }
                            // cout << "\n"; 
                            ans = true;
                            goto end;
                        }
                    } while (next_permutation(ord.begin(), ord.end()));
                }
            }
        }
        end:
        cout << (ans?"YES":"NO") << "\n";
    }
}