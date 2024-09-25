#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vt<int> hm;
    for (int i = 2; i <= 32; i++) {
        hm.push_back(stoi(bitset<6>(i).to_string()));
    }
    // cout << "hm" << endl;
    // for (int i = 0; i < hm.size(); i++) {
    //     cout << hm[i] << " ";
    // }
    // cout << endl;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = hm.size()-1; i >= 0; i--) {
            while (N % hm[i] == 0) {
                N /= hm[i];
                if (N == 1) break;
            }
        }
        // cout << "N: " << N << endl;
        if (N == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}