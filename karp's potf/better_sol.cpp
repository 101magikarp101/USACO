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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

typedef unsigned long long ull;

ull phi(ull n) {
	ull res = 1;
	if ((n & 1) == 0) {
		n >>= 1;
		while ((n & 1) == 0) {
			res <<= 1;
			n >>= 1;
		}
	}

	for (ull i = 3; n > 1; i += 2) {
		if (n % i == 0) {
			res *= (i - 1);
			n /= i;
			while (n % i == 0) {
				res *= i;
				n /= i;
			}
		}
	}

	return res;
}

ull modpow(ull b, ull e, ull m) {
	e = e == 0 ? phi(m) : e;
	ull res = 1;
	ull r = b % m;

	while (e) {
		if (e & 1) {
			res = (res * r) % m;
		}
		r = (r * r) % m;
		e >>= 1;
	}

	return res;
}

ull tower_pow(ull b, ull h, ull m) {
	if (h == 0) {
		return 1;
	}
	if (m == 1) {
		return 0;
	}
	ull e = tower_pow(b, h - 1, phi(m));
	return modpow(b, e, m);
}

ull tower(ull base, ull h, ull m)
{
	return m == 1 ? 0 : tower_pow(base, h, m);
}

int main () {
    // cout << pow(100, 1000) << endl;
    // cout << (pow(10, 100) > 2992 )<< endl;
    ull b, h, m;
    cin >> b >> h >> m;
    ull ans = tower(b, h, m);
    cout << ans << endl;
}