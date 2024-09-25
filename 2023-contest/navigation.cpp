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
#include <chrono>

#define ll long long

using namespace std;

double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

int N;
double x, y;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll b, d;
        cin >> b >> d;
        b = 90-b;
        x += d*cos(b*PI/180);
        y += d*sin(b*PI/180);
        cout << fixed << setprecision(3) << x << " " << y << endl;
    }
    double t = atan2(y, x);
    if (t < 0) {
        t += 2*PI;
    }
    t = t*180/PI;
    t = 270-t;
    if (t < 0) {
        t += 360;
    }
    cout << fixed << setprecision(3) << t << " " << sqrt(x*x+y*y) << endl;
}