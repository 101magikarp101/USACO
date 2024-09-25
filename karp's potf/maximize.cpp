#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll poly[5];
ll dx[4]; //dy/dx
ll dx2[3]; //d2y/dx2
ll a[200005];

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        ll x = 1;
        for (int j = 4; j >= 0; j--) {
            poly[j] += x;
            x *= a[i];
        }
    }
    poly[1] *= -4;
    poly[2] *= 6;
    poly[3] *= -4;
    for (int i = 0; i < 4; i++) {
        dx[i] = poly[i+1]*(i+1);
    }
    // for (int i = 0; i < 3; i++) {
    //     dx2[i] = dx[i+1]*(i+1);
    // }
    // cout << "y=" << poly[4] << "x^4" << showpos << poly[3] << "x^3" << poly[2] << "x^2" << poly[1] << "x" << poly[0] << endl;
    // cout << "dy/dx=" << dx[3] << "x^3" << showpos << dx[2] << "x^2" << dx[1] << "x" << dx[0] << endl;
    // cout << "d2y/dx2=" << dx2[2] << "x^2" << showpos << dx2[1] << "x" << dx2[0] << endl;
    //find all roots of the cubic equation dx[3]x^3+dx[2]x^2+dx[1]x+dx[0]
    //using Cardano's method
    vt<double> roots;
    double a = dx[3];
    double b = dx[2];
    double c = dx[1];
    double d = dx[0];
    double q = (3*a*c-b*b)/(9*a*a);
    double r = (9*a*b*c-27*a*a*d-2*b*b*b)/(54*a*a*a);
    double s = cbrt(r+sqrt(q*q*q+r*r));
    double t = cbrt(r-sqrt(q*q*q+r*r));
    double x1 = s+t-b/(3*a);
    cout << fixed << setprecision(10) << x1 << endl;
}