#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vt<vt<string>> hm = {{"D", "F", "J", "K"}, {"D", "F", "Sp", "J", "K"}, {"S", "D", "F", "J", "K", "L"}, {"S", "D", "F", "Sp", "J", "K", "L"}};
    cin >> N >> K;
    vt<string> k = hm[K-4];
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        string res = "";
        for (int i = 0; i < K; i++) {
            if (a&(1<<(K-i-1))) {
                res += k[i];
            }
        }
        cout << res << "\n";
    }
    return 0;
}