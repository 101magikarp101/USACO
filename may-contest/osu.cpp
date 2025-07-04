#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};
struct pdd {double x, y;};

struct circle {
    double x, y, r;
};

int N;
vt<circle> a;

vt<double> unitgradient(vt<double> &x, vt<circle> &v) {
    if (N==2) {
        //(2 r cos(x) (b - d + r sin(x)) - 2 r sin(x) (a - c + r cos(x)))/(2 sqrt((a - c + r cos(x))^2 + (b - d + r sin(x))^2)) + (2 r cos(x) (b + r sin(x)) - 2 r sin(x) (a + r cos(x)))/(2 sqrt((a + r cos(x))^2 + (b + r sin(x))^2))
        double res = (v[0].r*cos(x[0])*(v[0].y-v[1].y+v[0].r*sin(x[0]))-v[0].r*sin(x[0])*(v[0].x-v[1].x+v[0].r*cos(x[0]))) / sqrt((v[0].x-v[1].x+v[0].r*cos(x[0]))*(v[0].x-v[1].x+v[0].r*cos(x[0]))+(v[0].y-v[1].y+v[0].r*sin(x[0]))*(v[0].y-v[1].y+v[0].r*sin(x[0])));
        res += (v[0].r*cos(x[0])*(v[0].y+v[0].r*sin(x[0]))-v[0].r*sin(x[0])*(v[0].x+v[0].r*cos(x[0]))) / sqrt((v[0].x+v[0].r*cos(x[0]))*(v[0].x+v[0].r*cos(x[0]))+(v[0].y+v[0].r*sin(x[0]))*(v[0].y+v[0].r*sin(x[0])));
        return {res};
    } else {
        //(2 r cos(x) (b - d + r sin(x) - R sin(y)) - 2 r sin(x) (a - c + r cos(x) - R cos(y)))/(2 sqrt((a - c + r cos(x) - R cos(y))^2 + (b - d + r sin(x) - R sin(y))^2)) + (2 r cos(x) (b + r sin(x)) - 2 r sin(x) (a + r cos(x)))/(2 sqrt((a + r cos(x))^2 + (b + r sin(x))^2))
        double res1 = (v[0].r*cos(x[0])*(v[0].y-v[1].y+v[0].r*sin(x[0])-v[1].r*sin(x[1]))-v[0].r*sin(x[0])*(v[0].x-v[1].x+v[0].r*cos(x[0])-v[1].r*cos(x[1]))) / sqrt((v[0].x-v[1].x+v[0].r*cos(x[0])-v[1].r*cos(x[1]))*(v[0].x-v[1].x+v[0].r*cos(x[0])-v[1].r*cos(x[1]))+(v[0].y-v[1].y+v[0].r*sin(x[0])-v[1].r*sin(x[1]))*(v[0].y-v[1].y+v[0].r*sin(x[0])-v[1].r*sin(x[1])));
        res1 += (v[0].r*cos(x[0])*(v[0].y+v[0].r*sin(x[0]))-v[0].r*sin(x[0])*(v[0].x+v[0].r*cos(x[0])))/sqrt((v[0].x+v[0].r*cos(x[0]))*(v[0].x+v[0].r*cos(x[0]))+(v[0].y+v[0].r*sin(x[0]))*(v[0].y+v[0].r*sin(x[0])));
        //(2 R sin(y) (a - c + r cos(x) - R cos(y)) - 2 R cos(y) (b - d + r sin(x) - R sin(y)))/(2 sqrt((a - c + r cos(x) - R cos(y))^2 + (b - d + r sin(x) - R sin(y))^2)) + (2 R cos(y) (d - f + R sin(y)) - 2 R sin(y) (c - e + R cos(y)))/(2 sqrt((c - e + R cos(y))^2 + (d - f + R sin(y))^2))
        double res2 = (v[1].r*sin(x[1])*(v[0].x-v[1].x+v[0].r*cos(x[0])-v[1].r*cos(x[1]))-v[1].r*cos(x[1])*(v[0].y-v[1].y+v[0].r*sin(x[0])-v[1].r*sin(x[1])))/sqrt((v[0].x-v[1].x+v[0].r*cos(x[0])-v[1].r*cos(x[1]))*(v[0].x-v[1].x+v[0].r*cos(x[0])-v[1].r*cos(x[1]))+(v[0].y-v[1].y+v[0].r*sin(x[0])-v[1].r*sin(x[1]))*(v[0].y-v[1].y+v[0].r*sin(x[0])-v[1].r*sin(x[1])));
        res2 += (v[1].r*cos(x[1])*(v[1].y-v[2].y+v[1].r*sin(x[1]))-v[1].r*sin(x[1])*(v[1].x-v[2].x+v[1].r*cos(x[1])))/sqrt((v[1].x-v[2].x+v[1].r*cos(x[1]))*(v[1].x-v[2].x+v[1].r*cos(x[1]))+(v[1].y-v[2].y+v[1].r*sin(x[1]))*(v[1].y-v[2].y+v[1].r*sin(x[1])));
        return {res1, res2};
    }
}

double mag(vt<double> &v) {
    double res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += v[i]*v[i];
    }
    return sqrt(res);
}

double solve(vt<circle> &v) {
    vt<double> pos(N-1, 0);
    double d = 1e-5;
    vt<double> grad = {100, 100};
    for (int j = 0; j < 1000000; j++) {
        grad = unitgradient(pos, v);
        for (int i = 0; i < N-1; i++) {
            pos[i] -= d * grad[i];
        }
        // cout << "pos: ";
        // for (int i = 0; i < N-1; i++) {
        //     cout << pos[i] << ' ';
        // }
        // cout << '\n';
        // cout << "grad: ";
        // for (int i = 0; i < N-1; i++) {
        //     cout << grad[i] << ' ';
        // }
        // cout << '\n';
    }
    double ans = sqrt((v[0].x+v[0].r*cos(pos[0]))*(v[0].x+v[0].r*cos(pos[0])) + (v[0].y+v[0].r*sin(pos[0]))*(v[0].y+v[0].r*sin(pos[0])));
    ans += sqrt((v[N-2].x+v[N-2].r*cos(pos[N-2])-v[N-1].x)*(v[N-2].x+v[N-2].r*cos(pos[N-2])-v[N-1].x)+(v[N-2].y+v[N-2].r*sin(pos[N-2])-v[N-1].y)*(v[N-2].y+v[N-2].r*sin(pos[N-2])-v[N-1].y));
    if (N==3) {
        ans += sqrt((v[1].x+v[1].r*cos(pos[1])-(v[0].x+v[0].r*cos(pos[0])))*(v[1].x+v[1].r*cos(pos[1])-(v[0].x+v[0].r*cos(pos[0])))+(v[1].y+v[1].r*sin(pos[1])-(v[0].y+v[0].r*sin(pos[0])))*(v[1].y+v[1].r*sin(pos[1])-(v[0].y+v[0].r*sin(pos[0]))));
    }
    ans -= v[N-1].r;
    // cout << "pos: ";
    // for (int i = 0; i < N-1; i++) {
    //     cout << pos[i] << ' ';
    // }
    // cout << '\n';
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        circle c = {0, 0, 0};
        cin >> c.x >> c.y >> c.r;
        if (c.x*c.x+c.y*c.y > c.r*c.r) {
            a.push_back(c);
        }
    }
    N = a.size();
    if (N==0) {
        cout << "0.000\n";
        return 0;
    }
    if (N==1) {
        double ans = sqrt(a[0].x * a[0].x + a[0].y * a[0].y) - a[0].r;
        cout << fixed << setprecision(3) << ans << '\n';
        return 0;
    }
    //generate all permutations of the circles
    vt<int> perm(N);
    for (int i = 0; i < N; i++) {
        perm[i] = i;
    }
    double ans = 1e9;
    do {
        vt<circle> b;
        for (int i = 0; i < N; i++) {
            b.push_back(a[perm[i]]);
        }
        double res = solve(b);
        // if (res < ans) {
            // for (int i = 0; i < N; i++) {
            //     cout << perm[i] << ' ';
            // }
            // cout << '\n';
            // cout << res << '\n';
        // }
        ans = min(ans, res);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}