#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};
struct pdd {double x, y;};

pdd unitgrad(double x, double y) {
    //f_x(x,y)=\frac{\sin{x}(\cos{y}+4)-\cos{x}(\sin{y}-2)}{\sqrt{(-\sin{x}+\sin{y}-2)^2+(-\cos{x}+\cos{y}+4)^2}}+\frac{\sin{x}+2\cos{x}}{\sqrt{\sin^2{x}+4\sin{x}+\cos^2{x}-2\cos{x}+5}}
    //f_y(x,y)=\frac{(\cos{x}-4)\sin{y}-(\sin{x}+2)\cos{y}}{\sqrt{(-\sin{x}+\sin{y}-2)^2+(-\cos{x}+\cos{y}+4)^2}}+\frac{\sin{y}+3\cos{y}}{\sqrt{\sin^2{y}+6\sin{y}+\cos^2{y}-2\cos{y}+10}}
    double f_x = (sin(x)*(cos(y)+4)-cos(x)*(sin(y)-2))/sqrt(pow(-sin(x)+sin(y)-2,2)+pow(-cos(x)+cos(y)+4,2))+(sin(x)+2*cos(x))/sqrt(pow(sin(x),2)+4*sin(x)+pow(cos(x),2)-2*cos(x)+5);
    double f_y = ((cos(x)-4)*sin(y)-(sin(x)+2)*cos(y))/sqrt(pow(-sin(x)+sin(y)-2,2)+pow(-cos(x)+cos(y)+4,2))+(sin(y)+3*cos(y))/sqrt(pow(sin(y),2)+6*sin(y)+pow(cos(y),2)-2*cos(y)+10);
    double mag = sqrt(f_x*f_x+f_y*f_y);
    return {f_x/mag, f_y/mag};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double x = M_PI, y = M_PI;
    for (int i = 0; i < 100000000; i++) {
        pdd grad = unitgrad(x, y);
        x -= 0.00001*grad.x;
        y -= 0.00001*grad.y;
        // cout << x << " " << y << endl;
    }
    cout << fixed << setprecision(10) << x << " " << y << endl;
    return 0;
}