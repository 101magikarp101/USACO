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
#include <random>
#include <functional>

#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

struct prime {
    ull p, e, res;
};

ull tot(ull n) {
    ull res = n;
    for (ull i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            res -= res/i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res -= res/n;
    }
    return res;
}

ull gcd (ull a, ull b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ull binpow (ull a, ull b, ull m) {
    a %= m;
    ull res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res*a % m;
        }
        a = a*a % m;
        b >>= 1;
    }
    return res;
}

ull crt (vector<prime> pf, ull m) {
    //m = p1^e1 * p2^e2 * ... * pk^ek
    // cout << "m: " << m << endl;
    // cout << "pf: " << endl;
    // for (prime p : pf) {
    //     cout << p.p << " " << p.e << " " << p.res << endl;
    // }
    ull ans = 0;
    for (prime p : pf) {
        ull res = pow(p.p, p.e);
        ull M = m/res;
        ull M_inv = binpow(M, tot(res)-1, res);
        ans += p.res * M * M_inv;
        ans %= m;
    }
    // cout << "ans: " << ans << endl;
    return ans;
}

ull tower (ull b, ull h, ull m) {
    if (m == 1) return 0;
    if (h==0) return 1;
    if (h == 1) {
        return b % m;
    }
    if (m == 2) {
        return b % 2;
    }
    if (b==0 || b==1) {
        return b;
    }
    ull phi = tot(m);
    if (gcd(b, m) == 1) {
        return binpow(b, tower(b, h-1, phi), m);
    } else {
        vector<prime> pf;
        ull temp = m;
        for (ull i = 2; i*i <= temp; i++) {
            if (temp % i == 0) {
                prime p;
                p.p = i;
                p.e = 0;
                p.res = 0;
                while (temp % i == 0) {
                    temp /= i;
                    p.e++;
                }
                pf.push_back(p);
            }
        }
        if (temp > 1) {
            prime p;
            p.p = temp;
            p.e = 1;
            p.res = 0;
            pf.push_back(p);
        }
        if (pf.size() == 1) {
            ull cnt = 0;
            ull b1 = b;
            while (b1 % pf[0].p == 0) {
                b1 /= pf[0].p;
                cnt++;
            }
            ull res = 1;
            for (int i = 1; i < min(h, 6ull); i++) {
                res = pow(b, res);
                if (res * cnt >= pf[0].e) {
                    return 0;
                }
            }
            res = pow(b, res);
            return res % m;
        }
        for (int i = 0; i < pf.size(); i++) {
            pf[i].res = tower(b, h, pow(pf[i].p, pf[i].e));
            // cout << "b: " << b << " h: " << h << " m: " << m << " p: " << pf[i].p << " e: " << pf[i].e << " res: " << pf[i].res << endl;
        }
        ull ans = crt(pf, m);
        return ans;
    }
}

int main() {
    uniform_int_distribution<ll> dist(1, 1000000000);
    uniform_int_distribution<ll> dist2(1, 1e18);
    auto gen = bind(dist, mt19937(time(0)));
    auto gen2 = bind(dist2, mt19937(time(0)));
    for (int i = 0; i < 10; i++) {
        //write to file (i+1).in
        freopen(("test"+to_string(i+1)+".txt").c_str(), "w", stdout);
        ll B = gen();
        ll H = gen2();
        ll M = gen();
        cout << B << " " << H << " " << M << endl;
        fclose(stdout);
        freopen(("sol"+to_string(i+1)+".txt").c_str(), "w", stdout);
        cout << tower(B, H, M) << endl;
    }
}