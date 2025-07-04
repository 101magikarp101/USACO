#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll hm = 5'613'576'391'264'760'446LL;
    vt<int> v = {1, 200, 500, 2000, 5000, 20000, 50000, 200000, 500000, 2000000, 5000000};
    vt<string> res = {"tourist", "Legendary Grandmaster", "International Grandmaster", "Grandmaster", "International Master", "Master", "Candidate Master", "Expert", "Specialist", "Pupil", "Newbie"};
    ll s = (157039646LL)^hm;
    rnd.setSeed(s);
    ll n = rnd.next(1LL, 100000000LL);
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (n <= sum) {
            if (i <= 10) {
                string temp = res[i] + " hint given";
                const char* ans = temp.c_str();
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << "No hint given" << endl;
    // for (ll seed = 1; seed <= 100LL; seed++) {
    //     ll s = seed^hm;
    //     rnd.setSeed(s);
    //     ll n = rnd.next(1LL, 100000000LL);
    //     int sum = 0;
    //     for (int i = 0; i < v.size(); i++) {
    //         sum += v[i];
    //         if (n <= sum) {
    //             if (i <= 10) {
    //                 string temp = res[i] + " hint given";
    //                 const char* ans = temp.c_str();
    //                 cout << ans << endl;
    //             }
    //             break;
    //         }
    //     }
    // }
    return 0;
}