#include <iostream>
using namespace std;

const int MOD = 998244353;

int power(int x, int y) {
    int result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (1LL * result * x) % MOD;
        }
        y = y / 2;
        x = (1LL * x * x) % MOD;
    }
    return result;
}

int mod_inverse(int x) {
    return power(x, MOD - 2);
}

int count_situations(int n, int m, int k) {
    int fact[n + 1];
    int inv_fact[n + 1];

    fact[0] = 1;
    inv_fact[0] = 1;

    for (int i = 1; i <= n; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        inv_fact[i] = mod_inverse(fact[i]);
    }

    auto nCr = [&](int n, int r) {
        return (1LL * fact[n] * inv_fact[r] % MOD * inv_fact[n - r]) % MOD;
    };

    int result = 0;
    for (int i = 0; i <= k; ++i) {
        result = (result + 1LL * nCr(m - 1, i) * power(2, m - i - 1)) % MOD;
    }

    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int result = count_situations(n, m, k);
    cout << result << endl;

    return 0;
}
