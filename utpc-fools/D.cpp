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

double PI = 3.14159265358979323846;

double gamma(double n) {
    ll g = 7; // g represents the precision desired, p is the values of p[i] to plug into Lanczos' formula
    double p[] = {0.99999999999980993, 676.5203681218851, -1259.1392167224028, 771.32342877765313, -176.61502916214059, 12.507343278686905, -0.13857109526572012, 9.9843695780195716e-6, 1.5056327351493116e-7};
    if(n < 0.5) {
        return PI / sin(n * PI) / gamma(1 - n);
    }
    else {
        n--;
        double x = p[0];
        for(ll i = 1; i < g + 2; i++) {
          x += p[i] / (n + i);
        }
        double t = n + g + 0.5;
        return sqrt(2 * PI) * pow(t, (n + 0.5)) * exp(-t) * x;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << gamma(12) << endl;
    double l = 0.0, r = 5.0;
    double eps = 1e-9;
    while (r - l > eps) {
        double m = (l + r) / 2;
        if (gamma(m) < 1.847498857994100) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(9) << l << '\n';
    return 0;
}