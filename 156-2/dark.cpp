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

#define ll long long

using namespace std;

struct point {
    int x, y;
};

int T;
point P, A, B;

bool check(double m) {
    double da = sqrt((P.x - A.x) * (P.x - A.x) + (P.y - A.y) * (P.y - A.y));
    double da1 = sqrt(A.x * A.x + A.y * A.y);
    double db = sqrt((P.x - B.x) * (P.x - B.x) + (P.y - B.y) * (P.y - B.y));
    double db1 = sqrt(B.x * B.x + B.y * B.y);
    double d = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    d /= 2;
    if (m > max(da, da1)) {
        return true;
    }
    if (m > max(db, db1)) {
        return true;
    }
    if (m > d && m > min(da, db) && m > min(da1, db1)) {
        return true;
    }
    return false;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y;
        double l = 0;
        double r = 1e4;
        double m;
        while (r - l > 1e-6) {
            m = (l + r) / 2;
            if (!check(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << fixed << setprecision(6) << m << endl;
    }
}