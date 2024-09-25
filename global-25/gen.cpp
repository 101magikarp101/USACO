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
    string a = "Fikky";
    string s = "f";
    for (int i = 1; i <= 625; i++) {
        //x is 4th root of i
        int x = round(pow(i, 0.25));
        if (x*x*x*x == i) {
            s += a[x-1];
        } else {
            char t = (char)(rand()%2?rand()%26+65:rand()%26+97);
            s += t;
        }
    }
    cout << s << endl;
    return 0;
}