#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>

#define ll long long
using namespace std;

int BANG = 0;
int BUZZ = 1;
int CRASH = 2;
int FIBBI = 3;
int POP = 4;
int SQUAWK = 5;
int WHIZZ = 6;
int ZIP = 7;

struct fac {
    ll p, e;
};

vector<vector<fac>> factors;
vector<ll> fib;
map<ll, ll> memo;
vector<vector<int>> res;


ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

bool checkBang(ll n) {
    bool hasBang = n % 5 == 0;
    while (n > 0) {
        if (n % 10 == 5) {
            hasBang = true;
            break;
        }
        n /= 10;
    }
    return hasBang;
}

bool checkBuzz(ll n) {
    bool hasBuzz = n % 7 == 0;
    while (n > 0) {
        if (n % 10 == 7) {
            hasBuzz = true;
            break;
        }
        n /= 10;
    }
    return hasBuzz;
}

bool checkCrash(ll n) {
    return factors[n].size() == 1 && factors[n][0].e == 1;
}

bool checkFibbi(ll n) {
    return memo.find(n) != memo.end();
}

bool checkPop(ll n) {
    return factors[n].size() == 2 && factors[n][0].e == 1 && factors[n][1].e == 1;
}

bool checkSquawk(ll n) {
    bool hasSquawk = true;
    for (int i = 0; i < factors[n].size(); i++) {
        if (factors[n][i].p % 4 == 3 && factors[n][i].e % 2 == 1) {
            hasSquawk = false;
            break;
        }
    }
    return hasSquawk;
}

bool checkWhizz(ll n) {
    bool hasWhizz = true;
    for (int i = 0; i < factors[n].size(); i++) {
        if (factors[n][i].e != 1) {
            hasWhizz = false;
            break;
        }
    }
    return hasWhizz;
}

bool checkZip(ll n) {
    bool hasZip = true;
    if (factors[n].size() == 0) {
        return false;
    }
    if (factors[n].size() == 1) {
        return factors[n][0].e >= 2;
    }
    ll g = gcd(factors[n][0].e, factors[n][1].e);
    for (int i = 2; i < factors[n].size(); i++) {
        g = gcd(g, factors[n][i].e);
    }
    return g >= 2;
}


int main() {
    fib.push_back(1);
    fib.push_back(1);
    for (int i = 2; i <= 1000; i++) {
        fib.push_back(fib[i-1] + fib[i-2]);
    }
    for (int i = 0; i < fib.size(); i++) {
        memo[fib[i]] = i;
    }
    factors.push_back(vector<fac>());
    for (int i = 1; i <= 1000; i++) {
        factors.push_back(vector<fac>());
        ll n = i;
        for (ll j = 2; j*j <= n; j++) {
            if (n % j == 0) {
                ll e = 0;
                while (n % j == 0) {
                    n /= j;
                    e++;
                }
                factors[i].push_back({j, e});
            }
        }
        if (n > 1) {
            factors[i].push_back({n, 1});
        }
    }
    // cout << "factors" << endl;
    // for (int i = 1; i <= factors.size(); i++) {
    //     cout << i << ": ";
    //     for (auto f : factors[i]) {
    //         cout << f.p << "^" << f.e << " ";
    //     }
    //     cout << endl;
    // }
    for (ll i = 0; i < factors.size(); i++) {
        res.push_back(vector<int>());
        if (checkBang(i)) {
            res[i].push_back(BANG);
        }
        if (checkBuzz(i)) {
            res[i].push_back(BUZZ);
        }
        if (checkCrash(i)) {
            res[i].push_back(CRASH);
        }
        if (checkFibbi(i)) {
            res[i].push_back(FIBBI);
        }
        if (checkPop(i)) {
            res[i].push_back(POP);
        }
        if (checkSquawk(i)) {
            res[i].push_back(SQUAWK);
        }
        if (checkWhizz(i)) {
            res[i].push_back(WHIZZ);
        }
        if (checkZip(i)) {
            res[i].push_back(ZIP);
        }
    }
    ofstream fout("buzz.txt");
    for (int i = 1; i <= res.size(); i++) {
        fout << i << ": ";
        fout << string(to_string(res.size()).length() - to_string(i).length(), ' ');
        for (int j = 0; j <= 7; j++) {
            if (binary_search(res[i].begin(), res[i].end(), j)) {
                if (j == BANG) {
                    fout << "BANG ";
                }
                if (j == BUZZ) {
                    fout << "BUZZ ";
                }
                if (j == CRASH) {
                    fout << "CRASH ";
                }
                if (j == FIBBI) {
                    fout << "FIBBI ";
                }
                if (j == POP) {
                    fout << "POP ";
                }
                if (j == SQUAWK) {
                    fout << "SQUAWK ";
                }
                if (j == WHIZZ) {
                    fout << "WHIZZ ";
                }
                if (j == ZIP) {
                    fout << "ZIP ";
                }
            } else {
                if (j == BANG) {
                    fout << "     ";
                }
                if (j == BUZZ) {
                    fout << "     ";
                }
                if (j == CRASH) {
                    fout << "      ";
                }
                if (j == FIBBI) {
                    fout << "      ";
                }
                if (j == POP) {
                    fout << "    ";
                }
                if (j == SQUAWK) {
                    fout << "       ";
                }
                if (j == WHIZZ) {
                    fout << "      ";
                }
                if (j == ZIP) {
                    fout << "    ";
                }
            }
        }
        fout << endl;
    }
    fout.close();
}