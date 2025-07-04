#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns the minimum # of steps to reduce n->0 by repeatedly
// subtracting its current maximum decimal digit.
ll solve(ll n) {
    ll steps = 0;
    while (n > 0) {
        // 1) extract digits of n into digs[] (least to most significant)
        ll tmp = n;
        vector<int> digs;
        digs.reserve(20);
        while (tmp > 0) {
            digs.push_back(tmp % 10);
            tmp /= 10;
        }
        int D = digs.size();

        // 2) find current max digit c
        int c = 0;
        for (int d : digs) c = max(c, d);

        // 3) compute threshold of Type-1 break:
        //    find the *first* (most significant) position i where digs[i]==c,
        //    and form the largest number <n whose digit at i is (c-1)
        //    and every less‐significant digit = 9.
        ll thresh1 = 0;
        {
            ll pow10 = 1;
            // we'll build pow10 = 10^i
            for (int i = 0; i < D; i++) {
                if (digs[i] == c) {
                    // prefix = n / pow10
                    ll prefix = n / pow10;
                    // drop that c by 1, then fill the rest with 9's
                    ll t = (prefix - 1) * pow10 + (pow10 - 1);
                    thresh1 = t;
                    break;
                }
                pow10 *= 10;
            }
        }

        // 4) compute threshold of Type-2 borrow‐break:
        //    count how many trailing zeros (in the digits vector)
        //    then the first time you land on a multiple of 10^z you'll borrow
        //    and turn those zeros into 9's, giving you a new max digit > c
        ll thresh2 = 0;
        {
            int z = 0;
            while (z < D && digs[z] == 0) z++;
            if (z > 0) {
                ll pow10 = 1;
                for (int i = 0; i < z; i++) pow10 *= 10;
                // thresh2 = the largest multiple of pow10 below n
                thresh2 = n - (n % pow10);
            }
        }

        // 5) our true threshold is the *largest* of (thresh1, thresh2),
        //    because that's the *highest* value <n where the max‐digit regime changes.
        ll thresh = max(thresh1, thresh2);
        if (thresh < 0) thresh = 0;

        // 6) batch‐jump:
        //    we can subtract c repeatedly until we go <= thresh.
        //    that takes
        //        k = ceil((n - thresh) / c)
        //    exactly.
        ll diff = n - thresh;
        ll k    = (diff + c - 1) / c;

        n     -= k * c;
        steps += k;
    }
    return steps;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
