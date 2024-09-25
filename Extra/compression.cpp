#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int pre[5205][5205];

string hextobin(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c-'0' <= 9) {
            ans += bitset<4>(c-'0').to_string();
        } else {
            ans += bitset<4>(c-'A'+10).to_string();
        }
    }
    return ans;
}

bool check(int x) {
    int sz = N/x;
    bool good = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            int sum = pre[i*sz][j*sz]-pre[(i-1)*sz][j*sz]-pre[i*sz][(j-1)*sz]+pre[(i-1)*sz][(j-1)*sz];
            // cout << "sum: " << sum << endl;
            if (sum != 0 && sum != sz*sz) {
                good = 0;
                break;
            }
        }
    }
    return good;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        string bin = hextobin(s);
        for (int j = 0; j < bin.size(); j++) {
            pre[i][j+1] = bin[j]-'0';
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] += pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    vt<int> d;
    for (int i = 1; i*i <= N; i++) {
        if (N%i == 0) {
            d.push_back(i);
            if (i*i != N) {
                d.push_back(N/i);
            }
        }
    }
    sort(d.begin(), d.end());
    int ans = -1;
    for (int i = 0; i < d.size(); i++) {
        if (check(d[i])) {
            ans = d[i];
            break;
        }
    }
    cout << N/ans << endl;
    return 0;
}