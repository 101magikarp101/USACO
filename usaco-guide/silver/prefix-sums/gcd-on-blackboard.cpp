#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main () {
    int n;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int gcds[100000], gcds2[100000];
    gcds[0] = a[0];
    for (int i = 1; i < n; i++) {
        gcds[i] = gcd(gcds[i - 1], a[i]);
    }
    gcds2[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        gcds2[i] = gcd(gcds2[i + 1], a[i]);
    }
    int max = -1;
    for (int i = 0; i < n; i++) {
        int g;
        if (i > 0 && i < n-1) {
            g = gcd(gcds[i-1], gcds2[i + 1]);
        } else if (i == 0) {
            g = gcds2[i + 1];
        } else {
            g = gcds[i - 1];
        }
        if (g > max) max = g;
    }
    cout << max << endl;
}